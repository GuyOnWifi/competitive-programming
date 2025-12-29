// https://onlinejudge.org/external/7/713.pdf

#include <bits/stdc++.h>

using namespace std;

int main() {
  int testcases;
  cin >> testcases;

  for (int tc = 0; tc < testcases; tc++) {
    vector<int> a;
    vector<int> b;

    string sa, sb;
    cin >> sa >> sb;

    for (auto c : sa) {
      a.push_back(c - '0');
    }

    for (auto c : sb) {
      b.push_back(c - '0');
    }

    int size = max(a.size(), b.size());
    vector<int> result(size + 1);

    int carry = 0;
    for (int i = 0; i <= size - 1; i++) {
      int sum = 0;
      if (i < a.size()) {
        sum += a[i];
      }

      if (i < b.size()) {
        sum += b[i];
      }

      sum += carry;

      carry = sum / 10;
      sum = sum % 10;

      result[i] = sum;
    }
    result[size] = carry;

    bool leading_zero = true;
    for (int i = 0; i < result.size() - 1; i++) {
      if (result[i] == 0 && leading_zero)
        continue;
      else {
        leading_zero = false;
        cout << result[i];
      }
    }
    if (result[result.size() - 1] != 0) {
      cout << result[result.size() - 1];
    }
    cout << endl;
  }
}
