// https://dmoj.ca/problem/aaaa1p1

#include <bits/stdc++.h>

using namespace std;

// true if even

int main() {
  int N;
  cin >> N;

  int num_even = 0;
  int num_odd = 0;
  for (int i = 0; i < N; i++) {
    long long a;
    cin >> a;

    if (a % 2 == 0) {
      num_even++;
    } else {
      num_odd++;
    }
  }

  if (N % 2 == 0) {
    // end on Todd

    if (num_odd > num_even) {
      cout << "Todd" << endl;
    } else {
      cout << "Steven" << endl;
    }
  } else {
    cout << "Steven" << endl;
  }
}
