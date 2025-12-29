// https://codeforces.com/contest/433/problem/B

#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> stones;
  for (int i = 0; i < n; i++) {
    int cost;
    cin >> cost;
    stones.push_back(cost);
  }

  vector<long long> psa(stones.size() + 1, 0);
  for (int i = 1; i <= stones.size(); i++) {
    psa[i] = psa[i - 1] + stones[i - 1];
  }

  sort(stones.begin(), stones.end());
  vector<long long> psa_sorted(stones.size() + 1, 0);
  for (int i = 1; i <= stones.size(); i++) {
    psa_sorted[i] = psa_sorted[i - 1] + stones[i - 1];
  }

  int m;
  cin >> m;

  while (m--) {
    int t, l, r;
    cin >> t >> l >> r;
    if (t == 1) {
      cout << psa[r] - psa[l - 1] << endl;
    } else {
      cout << psa_sorted[r] - psa_sorted[l - 1] << endl;
    }
  }
}
