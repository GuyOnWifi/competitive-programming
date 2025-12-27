// https://dmoj.ca/problem/aaaa1p3

#include <bits/stdc++.h>

using namespace std;

int heights[2000005];
unordered_map<int, vector<int>> height_map;
vector<int> submerged;
bool is_submerged[2000005];

int main() {
  int T, N;
  cin >> T >> N;

  for (int i = 0; i < N; i++) {
    cin >> heights[i];
    height_map[heights[i]].push_back(i);
  }

  int start_idx = 0;
  for (int i = 0; i < N; i++) {
    if (heights[i] != 0) {
      start_idx = i;
      break;
    }
    is_submerged[i + 1] = true;
  }

  int stop_idx = -1;
  for (int i = N - 1; i >= 0; i--) {
    if (heights[i] != 0) {
      stop_idx = i;
      break;
    }
    is_submerged[i + 1] = true;
  }

  if (stop_idx == -1) {
    for (int s = 0; s < N; s++) {
      cout << "0 ";
    }
    cout << endl;
    return 0;
  }

  int islands = 1;
  for (int i = start_idx; i <= stop_idx; i++) {
    if (heights[i] == 0) {
      islands++;
      is_submerged[i + 1] = true;
    }
  }

  cout << islands << " ";

  is_submerged[0] = true;
  is_submerged[N + 1] = true;
  for (int i = 1; i < N; i++) {
    for (auto idx : height_map[i]) {
      if (is_submerged[idx] && is_submerged[idx + 2]) {
        islands--;
      } else if (!is_submerged[idx] && !is_submerged[idx + 2]) {
        islands++;
      }
      is_submerged[idx + 1] = true;
    }
    cout << islands << " ";
  }
  cout << endl;
}
