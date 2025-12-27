// https://dmoj.ca/problem/aaaa1p2

#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> lights;
  vector<int> friends;

  for (int i = 0; i < N; i++) {
    int l;
    cin >> l;
    lights.push_back(l);
  }

  for (int i = 0; i < M; i++) {
    int f;
    cin >> f;
    friends.push_back(f);
  }

  sort(lights.begin(), lights.end());
  sort(friends.begin(), friends.end());

  int power = 0;

  if (lights[0] > friends[0]) {
    power += lights[0] - friends[0];
  }

  if (lights[lights.size() - 1] < friends[friends.size() - 1]) {
    power += friends[friends.size() - 1] - lights[lights.size() - 1];
  }

  for (int l = 0; l < lights.size() - 1; l++) {
    // go between indexes  l and l + 1
    int start_idx = upper_bound(friends.begin(), friends.end(), lights[l]) -
                    friends.begin();
    int stop_idx = lower_bound(friends.begin(), friends.end(), lights[l + 1]) -
                   friends.begin() - 1;

    if (start_idx == friends.size() || friends[start_idx] >= lights[l + 1])
      continue;

    int ans = INT_MAX;
    for (int i = start_idx; i <= stop_idx - 1; i++) {
      ans = min(ans, friends[i] - lights[l] + lights[l + 1] - friends[i + 1]);
    }

    ans = min(ans, lights[l + 1] - friends[start_idx]);
    ans = min(ans, friends[stop_idx] - lights[l]);

    power += ans;
  }

  cout << power << endl;
}
