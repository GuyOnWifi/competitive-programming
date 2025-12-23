#include <bits/stdc++.h>

using namespace std;

vector<int> add(vector<int> &x, vector<int> &y) {
  int size = max(x.size(), y.size());
  vector<int> res(size + 1);

  int carry = 0;
  for (int i = -1; i >= -size; i--) {
    int sum = 0;
    if (i + (int)x.size() >= 0) {
      sum += x[i + (int)x.size()];
    }
    if (i + (int)y.size() >= 0) {
      sum += y[i + (int)y.size()];
    }
    sum += carry;
    res[i + size + 1] = (sum % 10);
    carry = sum / 10;
  }
  res[0] = carry;

  return res;
}

vector<int> mult(vector<int> &x, vector<int> &y) {
  vector<int> res = {0};
  for (int i = 0; i < y.size(); i++) {
    vector<int> prod;
    for (auto n : x) {
      prod.push_back(n * y[i]);
    }

    for (int j = 0; j < y.size() - 1 - i; j++) {
      prod.push_back(0);
    }

    res = add(res, prod);
  }

  return res;
}

int main() {

  string x, y;
  while (cin >> x && cin >> y) {
    vector<int> xv;
    for (auto c : x) {
      xv.push_back(c - '0');
    }

    vector<int> yv;
    for (auto c : y) {
      yv.push_back(c - '0');
    }

    auto res = mult(xv, yv);
    // trim leading 0?
    bool leading = true;
    for (int i = 0; i < res.size() - 1; i++) {
      if (res[i] == 0 && leading) {
        continue;
      } else {
        leading = false;
        cout << res[i];
      }
    }
    cout << res[res.size() - 1];
    cout << "\n";
  }
}
