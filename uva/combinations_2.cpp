// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=305

#include <bits/stdc++.h>

using namespace std;

int memo[101][101];

int choose(int n, int k) {
  if (k == 0 || k == n || n == 1)
    return 1;
  if (memo[n][k] != -1) {
    return memo[n][k];
  }
  return memo[n][k] = choose(n - 1, k - 1) + choose(n - 1, k);
}

int main() {
  int N, M;
  memset(memo, -1, sizeof(memo));
  while (cin >> N >> M && !(N == 0 && M == 0)) {
    cout << N << " things taken " << M << " at a time is " << choose(N, M)
         << " exactly." << endl;
  }
}
