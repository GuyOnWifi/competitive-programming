// An Animal Contest 1 P2 - Alpaca Racing
// 4m15s

#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

long long arr[1000001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long N, D, K, X;
  cin >> N >> D >> K >> X;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  long long speed;
  cin >> speed;

  long long total = 0;
  for (int i = 0; i < N; i++) {
    while (arr[i] >= speed) {
      arr[i] = (long long)(arr[i] * (100 - X) / 100);
      total++;
      if (total > K) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }

  cout << "YES" << endl;
}
