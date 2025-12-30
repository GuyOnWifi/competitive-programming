// https://codeforces.com/problemset/problem/2181/M

#include <bits/stdc++.h>

using namespace std;

int a[1000001];
int b[1000001];

int num_flips(int a1, int a2, int b1, int b2) {
  int flips = 0;
  if (a1 != b1)
    flips++;
  if (a2 != b2)
    flips++;
  return flips;
}

int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    string sx, sy;
    cin >> sx >> sy;
    vector<vector<int>> dp(sx.size(), vector<int>(2, INT_MAX));

    for (int i = 0; i < sx.size(); i++) {
      a[i] = sx[i] - '0';
      b[i] = sy[i] - '0';
    }

    dp[0][0] = num_flips(0, 0, a[0], b[0]);
    dp[0][1] = num_flips(1, 1, a[0], b[0]);

    for (int j = 1; j < sx.size(); j++) {
      for (int i = 0; i < 4; i++) {
        int cur_x = (i >> 1) & 1;
        int cur_y = i & 1;

        int cost = num_flips(cur_x, cur_y, a[j], b[j]);

        int before = cur_x ^ cur_y;

        dp[j][cur_y] = min(dp[j - 1][before] + cost, dp[j][cur_y]);
      }
    }

    cout << min(dp[sx.size() - 1][0], dp[sx.size() - 1][1]) << "\n";
  }
}
