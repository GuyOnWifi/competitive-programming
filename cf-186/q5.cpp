// https://codeforces.com/problemset/problem/2182/E
// Was not solved during contest

#include <bits/stdc++.h>

using namespace std;

int main() {
  int tc;
  cin >> tc;

  while (tc--) {
    int n, m;
    long long k;
    cin >> n >> m >> k;

    vector<pair<int, int>> boxes;
    for (int i = 0; i < m; i++) {
      int beauty;
      cin >> beauty;
      boxes.push_back({beauty, 0});
    }

    long long total_spendings = 0;
    vector<tuple<int, int, bool>> friends; // extra coins, beauty, processed
    for (int i = 0; i < n; i++) {
      int x, y, z;
      cin >> x >> y >> z;
      total_spendings += y;
      friends.push_back({z - y, x, false});
    }

    sort(friends.begin(), friends.end());
    sort(boxes.begin(), boxes.end());

    int num_happy = 0;
    long long leftover = k - total_spendings;
    for (int i = friends.size() - 1; i >= 0; i--) {
      auto idx = lower_bound(boxes.begin(), boxes.end(), get<1>(friends[i]));
      if (idx != boxes.end()) {
        num_happy += 1;
        boxes.erase(idx);
        auto [c, b, p] = friends[i];
        friends[i] = {c, b, true};
      }
    }

    for (int i = 0; i < friends.size(); i++) {
      if (get<2>(friends[i]))
        continue;

      auto [c, b, p] = friends[i];

      if (c <= leftover) {
        leftover -= c;
        num_happy++;
      }
    }

    cout << num_happy << "\n";
  }
}
