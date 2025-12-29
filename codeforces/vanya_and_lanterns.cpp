// https://codeforces.com/contest/492/problem/B

#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

int main() {
  int n, l;
  cin >> n >> l;
  vector<int> lanterns;

  cout << fixed << setprecision(11);
  for (int i = 0; i < n; i++) {
    int lantern;
    cin >> lantern;
    lanterns.push_back(lantern);
  }

  sort(lanterns.begin(), lanterns.end());

  double ans = 0;
  for (int i = 0; i < lanterns.size() - 1; i++) {
    ans = max(ans, (lanterns[i + 1] - lanterns[i]) / 2.0);
  }

  ans = max(ans, (double)lanterns[0]);
  ans = max(ans, (double)l - lanterns[lanterns.size() - 1]);

  cout << ans << endl;
}
