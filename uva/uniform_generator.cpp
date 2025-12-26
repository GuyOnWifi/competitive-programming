#include <bits/stdc++.h>

using namespace std;

int main() {
  int step, mod;
  while (cin >> step >> mod) {
    int prev = 0;
    unordered_set<int> seen;
    seen.insert(0);
    for (int i = 0; i < mod - 1; i++) {
      prev = (prev + step) % mod;
      seen.insert(prev);
    }

    string step_s = to_string(step);
    for (int i = 0; i < 10 - step_s.size(); i++) {
      cout << " ";
    }
    cout << step_s;

    string mod_s = to_string(mod);
    for (int i = 0; i < 10 - mod_s.size(); i++) {
      cout << " ";
    }
    cout << mod_s;

    for (int i = 0; i < 4; i++) {
      cout << " ";
    }
    if (seen.size() == mod) {
      cout << "Good Choice";
    } else {
      cout << "Bad Choice";
    }

    cout << "\n\n";
  }
}
