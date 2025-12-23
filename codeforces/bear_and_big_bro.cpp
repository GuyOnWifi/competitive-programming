#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

/*
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b;
  cin >> a >> b;

  int years = 0;
  while (true) {
    a *= 3;
    b *= 2;
    years++;
    if (a > b) {
        break;
    }
  }
  cout << years;
}
*/

int main() {
  int a, b;
  cin >> a >> b;

  cout << floor(log((float)a / b) / log(2.0 / 3.0) + 1e-6) + 1 << endl;
}
