#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  vector<int> heights;
  for (int i = 0; i < N; i++) {
    int h;
    cin >> h;
    heights.push_back(h);
  }

  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int query;
    cin >> query;

    auto idx1 = lower_bound(heights.begin(), heights.end(), query);
    if (idx1 == heights.begin()) {
      cout << "X ";
    } else {
      cout << *--idx1 << " ";
    }

    auto idx2 = upper_bound(heights.begin(), heights.end(), query);
    if (idx2 == heights.end()) {
      cout << "X";
    } else {
      cout << *idx2;
    }
    cout << "\n";
  }
}
