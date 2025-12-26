#include <bits/stdc++.h>

using namespace std;

int main() {
  cout << fixed << setprecision(12);
  int n, k;
  cin >> n >> k;

  int prev_x, prev_y;
  cin >> prev_x >> prev_y;
  double total_dist = 0;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    int dx = x - prev_x;
    int dy = y - prev_y;

    double dist = sqrt((double)dx * dx + dy * dy);
    total_dist += dist;
    prev_x = x;
    prev_y = y;
  }

  cout << total_dist * k / 50.0 << endl;
}
