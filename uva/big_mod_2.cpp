// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=310

#include <bits/stdc++.h>

using namespace std;

int main() {
  int B, P, M;
  while (cin >> B >> P >> M) {
    long long res = 1;
    long long pow = B % M;
    while (P > 0) {
      if (P & 1) {
        res = (res * pow) % M;
      }
      pow = (pow * pow) % M;
      P >>= 1;
    }
    cout << res << endl;
  }
}
