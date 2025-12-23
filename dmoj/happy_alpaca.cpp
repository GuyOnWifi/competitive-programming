#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

int happiness[1000002];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, X;

  cin >> N >> X;

  int reduced = (N - X);

  if (reduced % 2 == 1) {
    cout << "-1" << endl;
    return 0;
  }

  string ans = "";

  for (int i = 0; i < reduced / 2; i++) {
    ans += "1 0 ";
  }
  for (int i = 0; i < N - (reduced); i++) {
    ans += "1 ";
  }

  cout << ans.substr(0, ans.length() - 1) << endl;
}
