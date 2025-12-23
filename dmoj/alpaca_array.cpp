#include <algorithm>
#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

int arr[1000002];
unordered_map<int, vector<int>> seen;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, Q;
  cin >> N >> Q;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    seen[arr[i]].push_back(i);
  }

  for (int i = 0; i < Q; i++) {
    int l, r, x;
    cin >> l >> r >> x;

    // compensate for one indexing
    l -= 1;
    r -= 1;
    bool possible = false;
    for (int i = 1; i < sqrt(x); i++) {
      if (x % i != 0)
        continue;

      int opposite = x / i;
      auto idx = lower_bound(seen[i].begin(), seen[i].end(), l);
      auto idx2 = lower_bound(seen[opposite].begin(), seen[opposite].end(), l);
      if (idx != seen[i].end() && *idx <= r && idx2 != seen[opposite].end() &&
          *idx2 <= r) {
        possible = true;
      }
    }
    cout << (possible ? "YES" : "NO") << "\n";
  }
}
