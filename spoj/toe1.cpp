// https://www.spoj.com/problems/TOE1/

#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  while (N--) {
    int num_x = 0;
    int num_o = 0;

    for (int i = 0; i < 9; i++) {
      char c;
      cin >> c;
      if (c == 'X') {
        num_x++;
      } else if (c == 'O') {
        num_o++;
      }
    }

    if (num_x == num_o || num_x == num_o + 1) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
}
