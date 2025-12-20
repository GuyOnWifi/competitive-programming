#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

int arr[1000002];
unordered_map<int, set<int>> seen;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, Q;
  cin >> N >> Q;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    seen[arr[i]].insert(i);
  }

  for (int i = 0; i < Q; i++) {
    int l, r, x;
    cin >> l >> r >> x;
    bool possible = false;
    for (int i = 0; i < sqrt(x); i++) {
      if (x % i != 0)
        continue;

      int opposite = x / i;
      auto idx = seen[i].lower_bound(l);
      auto idx2 = seen[opposite].lower_bound(l);
      if (idx != seen[i].end()) {
        if (*idx <= r) {
        }
      }
    }
    cout << (possible ? "YES" : "NO") << "\n";
  }
}
