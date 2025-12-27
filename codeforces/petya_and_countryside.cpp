// https://codeforces.com/contest/66/problem/B

#include <bits/stdc++.h>

using namespace std;

int heights[1001];
int order[1001];
int order_rev[1001];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> heights[i];
  }

  order[0] = 0;
  for (int i = 1; i < n; i++) {
    if (heights[i] >= heights[i - 1]) {
      order[i] = order[i - 1] + 1;
    } else {
      order[i] = 0;
    }
  }

  order_rev[n - 1] = 0;
  for (int i = n - 2; i >= 0; i--) {
    if (heights[i] >= heights[i + 1]) {
      order_rev[i] = order_rev[i + 1] + 1;
    } else {
      order_rev[i] = 0;
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(order[i] + order_rev[i] + 1, ans);
  }

  cout << ans << endl;
}
