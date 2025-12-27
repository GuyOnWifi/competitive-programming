// https://codeforces.com/contest/746/problem/B
//

#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<char> input;
  vector<char> output;

  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    input.push_back(c);
  }

  for (int i = input.size() - 1; i >= 0; i--) {
    int idx = output.size() / 2;
    output.insert(output.begin() + idx, input[i]);
  }

  for (auto c : output) {
    cout << c;
  }
  cout << endl;
}
