// https://codeforces.com/contest/2182/problem/D

#include <bits/stdc++.h>
#include <cstring>

using namespace std;

const int MOD = 998244353;

int deco[52];

long long dp[52][52];
long long choose_mod(int n, int k) {
  if (dp[n][k] != -1) {
    return dp[n][k];
  }

  if (k == 0 || k == n) {
    return 1;
  }

  return dp[n][k] =
             (choose_mod(n - 1, k - 1) % MOD + choose_mod(n - 1, k) % MOD) %
             MOD;
}

long long fact_dp[52];
long long fact(int n) {
  if (fact_dp[n] != -1) {
    return fact_dp[n];
  }

  if (n <= 1)
    return 1;

  return fact_dp[n] = (n * fact(n - 1)) % MOD;
}

int main() {
  memset(dp, -1, sizeof(dp));
  memset(fact_dp, -1, sizeof(fact_dp));
  int tc;
  cin >> tc;

  while (tc--) {
    memset(deco, 0, sizeof(deco));
    int n;
    cin >> n;

    int total = 0;
    for (int i = 0; i <= n; i++) {
      cin >> deco[i];
      total += deco[i];
    }

    int base = total / n;
    int extra = total % n;

    int num_start = 0;
    for (int i = 1; i <= n; i++) {
      if (deco[i] > base + 1) {
        num_start = extra + 1;
        break;
      } else if (deco[i] == base + 1) {
        num_start++;
      }
    }

    if (num_start > extra) {
      cout << "0\n";
      continue;
    }

    long long permute = (choose_mod(extra, num_start) * fact(num_start)) % MOD;
    long long fac = fact(n - num_start);
    // cout << choose << endl;
    // cout << fac << endl;
    cout << (permute * fac) % MOD << "\n";
  }
}
