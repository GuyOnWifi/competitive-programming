// https://codeforces.com/contest/2182/problem/A

#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int s;
    cin >> s;
    string str;
    cin >> str;

    int num_2025 = 0;
    for (int i = 0; i < str.size() - 3; i++) {
      if (str.substr(i, 4) == "2025") {
        num_2025++;
      }
    }

    int num_change = 100000;
    for (int i = 0; i < str.size() - 3; i++) {
      int to_change = 4;
      if (str[i] == '2')
        to_change--;
      if (str[i + 1] == '0')
        to_change--;
      if (str[i + 2] == '2')
        to_change--;
      if (str[i + 3] == '6')
        to_change--;

      num_change = min(num_change, to_change);
    }

    cout << min(num_2025, num_change) << "\n";
  }
}
