// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=310

#include <bits/stdc++.h>

#define ull unsigned long long;

using namespace std;

unsigned long long mods[33];

int main() {
  int B, P, M;
  while (cin >> B >> P >> M) {
    mods[0] = B % M;

    for (int i = 1; i < 31; i++) {
      mods[i] = (mods[i - 1] * mods[i - 1]) % M;
    }

    long long start = pow(2, 30);
    int pow = 30;
    long long ans = 1;
    while (P > 0) {
      if (P >= start) {
        P -= start;
        ans = (ans * mods[pow]) % M;
      }
      start /= 2;
      pow--;
    }

    cout << ans << endl;
  }
}
