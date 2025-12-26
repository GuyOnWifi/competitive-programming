#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, c;
  while (cin >> n >> m >> c && n != 0 && m != 0) {
    int black_row = ceil((m - 7 - 1) / 2.0);
    int white_row = ceil((m - 7) / 2.0);

    int num_black_row = ceil((n - 7 - c) / 2.0);
    int num_white_row = (n - 7) - num_black_row;

    cout << black_row * num_black_row + white_row * num_white_row << "\n";
  }
}
