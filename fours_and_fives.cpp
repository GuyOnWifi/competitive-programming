// CCC '22 S1 - Good Fours and Good Fives

#include <bits/stdc++.h>

using namespace std;

int main() {
  int num;
  cin >> num;

  int tmp = ceil((float)num / 5);
  int num_fours = tmp * 5 - num;
  int num_fives = (num - (num_fours * 4)) / 5;

  if (num_fives < 0) {
    cout << 0;
  } else {
    cout << floor(num_fives / 4) + 1;
  }
}
