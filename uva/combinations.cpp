// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=305

#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M;
  while (cin >> N >> M && !(N == 0 && M == 0)) {
    int one = M;
    int two = N - M;

    int biggest = max(one, two);
    int smallest = min(one, two);
    double ans = 1;

    int i = N;
    int j = 1;
    while (i > biggest || j <= smallest) {
      if (i > biggest)
        ans *= i;
      if (j <= smallest)
        ans /= j;
      i--;
      j++;
    }

    cout << N << " things taken " << M << " at a time is "
         << (int)(ans + 0.00000000001) << " exactly." << endl;
  }
}
