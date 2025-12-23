#include <bits/stdc++.h>

using namespace std;

vector<int> mult(vector<int> &x, vector<int> &y) {
  vector<int> res(x.size() + y.size());

  for (int i = 0; i < x.size(); i++) {
    for (int j = 0; j < y.size(); j++) {
      res[i + j] += x[i] * y[j];
      res[i + j + 1] += res[i + j] / 10;
      res[i + j] %= 10;
    }
  }
  return res;
}

int main() {
  string x;
  string y;
  while (cin >> x && cin >> y) {
    vector<int> xv;
    for (auto c : x) {
      xv.push_back(c - '0');
    }
    reverse(xv.begin(), xv.end());

    vector<int> yv;
    for (auto c : y) {
      yv.push_back(c - '0');
    }
    reverse(yv.begin(), yv.end());

    auto res = mult(xv, yv);
    reverse(res.begin(), res.end());
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
