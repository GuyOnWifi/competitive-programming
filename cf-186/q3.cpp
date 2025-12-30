// https://codeforces.com/contest/2182/problem/C

#include <bits/stdc++.h>

using namespace std;

int snowmen[3][5000];

int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    memset(snowmen, 0, sizeof(snowmen));
    int n;
    cin >> n;

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < n; j++) {
        cin >> snowmen[i][j];
      }
    }

    long long num_valid = 0;
    for (int i = 0; i < n; i++) {
      bool valid = true;
      for (int j = 0; j < n; j++) {
        int index = (i + j) % n;
        if (snowmen[0][index] >= snowmen[1][j]) {
          valid = false;
          break;
        }
      }
      if (valid) {
        num_valid++;
      }
    }

    long long num_valid_2 = 0;
    for (int j = 0; j < n; j++) {
      bool valid = true;
      for (int k = 0; k < n; k++) {
        int index = (j + k) % n;
        if (snowmen[1][index] >= snowmen[2][k]) {
          valid = false;
          break;
        }
      }
      if (valid) {
        num_valid_2++;
      }
    }

    cout << num_valid * num_valid_2 * n << "\n";
  }
}
