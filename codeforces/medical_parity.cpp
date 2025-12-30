// https://codeforces.com/problemset/problem/2181/M

#include <bits/stdc++.h>

using namespace std;

int dp[1000001][4];
bool x[1000001];
bool y[1000001];

int num_flips(bool a1, bool a2, bool b1, bool b2) {
  int flips = 0;
  if (a1 != b1)
    flips++;
  if (a2 != b2)
    flips++;
  return flips;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    string sx, sy;
    cin >> sx >> sy;

    for (int i = 0; i < sx.size(); i++) {
      x[i] = sx[i] - '0';
      y[i] = sy[i] - '0';
    }

    dp[0][0] = num_flips(0, 0, x[0], y[0]);
    // dp[0][1] = num_flips(0, 1, x[0], y[0]);
    // dp[0][2] = num_flips(1, 0, x[0], y[0]);
    dp[0][3] = num_flips(1, 1, x[0], y[0]);

    dp[0][1] = 100000000;
    dp[0][2] = 100000000;

    for (int i = 1; i < sx.size(); i++) {
      dp[i][0] = num_flips(0, 0, x[i], y[i]) + min(dp[i - 1][2], dp[i - 1][0]);
      dp[i][1] = num_flips(0, 1, x[i], y[i]) + min(dp[i - 1][1], dp[i - 1][3]);
      dp[i][2] = num_flips(1, 0, x[i], y[i]) + min(dp[i - 1][1], dp[i - 1][3]);
      dp[i][3] = num_flips(1, 1, x[i], y[i]) + min(dp[i - 1][2], dp[i - 1][0]);
    }

    int last = sx.size() - 1;
    cout << min(min(dp[last][2], dp[last][3]), min(dp[last][0], dp[last][1]))
         << "\n";
  }
}
