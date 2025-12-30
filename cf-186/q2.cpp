// https://codeforces.com/contest/2182/problem/B
#include <bits/stdc++.h>

using namespace std;

int main() {
  int tc;
  cin >> tc;

  while (tc--) {
    int a, b;
    cin >> a >> b;

    int ans = 0;

    {
      // if white on top
      int white = a;
      int layer = 1;
      int num_white_layer = 0;
      while (layer <= white) {
        white -= layer;
        layer *= 4;
        num_white_layer++;
      }

      // black on bottom
      int black = b;
      layer = 2;
      int num_black_layer = 0;
      while (layer <= black) {
        black -= layer;
        layer *= 4;
        num_black_layer++;
      }

      if (num_white_layer < num_black_layer) {
        ans = num_white_layer * 2;
      } else if (num_black_layer < num_white_layer) {
        ans = num_black_layer * 2 + 1;
      } else {
        ans = num_white_layer * 2;
      }
    }

    {
      // if white on bottom
      int white = a;
      int layer = 2;
      int num_white_layer = 0;
      while (layer <= white) {
        white -= layer;
        layer *= 4;
        num_white_layer++;
      }

      // black on top
      int black = b;
      layer = 1;
      int num_black_layer = 0;
      while (layer <= black) {
        black -= layer;
        layer *= 4;
        num_black_layer++;
      }

      if (num_white_layer < num_black_layer) {
        ans = max(ans, num_white_layer * 2 + 1);
      } else if (num_black_layer < num_white_layer) {
        ans = max(ans, num_black_layer * 2);
      } else {
        ans = max(ans, num_white_layer * 2);
      }
    }

    cout << ans << "\n";
  }
}
