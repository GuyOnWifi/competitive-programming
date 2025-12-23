// https://codeforces.com/contest/732/problem/A

#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k, r;
  cin >> k >> r;

  int num = 1;
  while (true) {
    if (k * num % 10 == 0 || k * num % 10 == r) {
      break;
    }
    num++;
  }

  cout << num << endl;
}
