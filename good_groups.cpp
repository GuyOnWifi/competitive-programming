// CCC '22 S2 - Good Groups

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

unordered_map<string, vector<string>> same;
unordered_map<string, vector<string>> different;

int main() {
  int X;
  cin >> X;

  while (X--) {
    string a, b;
    cin >> a >> b;
    same[a].push_back(b);
  }

  int Y;
  cin >> Y;
  while (Y--) {
    string a, b;
    cin >> a >> b;
    different[a].push_back(b);
  }

  int violated = 0;
  int G;
  cin >> G;
  while (G--) {
    string a, b, c;
    cin >> a >> b >> c;

    if (same.count(a)) {
      for (auto &x : same[a]) {
        if (b != x && c != x)
          violated++;
      }
    }
    if (same.count(b)) {
      for (auto &x : same[b]) {
        if (a != x && c != x)
          violated++;
      }
    }
    if (same.count(c)) {
      for (auto &x : same[c]) {
        if (b != x && a != x)
          violated++;
      }
    }

    if (different.count(a)) {
      for (auto &x : different[a]) {
        if (b == x || c == x)
          violated++;
      }
    }
    if (different.count(b)) {
      for (auto &x : different[b]) {
        if (a == x || c == x)
          violated++;
      }
    }
    if (different.count(c)) {
      for (auto &x : different[c]) {
        if (b == x || a == x)
          violated++;
      }
    }
  }
  cout << violated;
}
