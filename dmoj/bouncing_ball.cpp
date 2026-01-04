#include <bits/stdc++.h>

using namespace std;

bool comp(double a, double b) { return abs(a - b) < 0.000000001; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, p, q;
  cin >> n >> m >> p >> q;

  double slope = (double)q / (n - p);
  double b = -slope * p;

  int i = 1;
  int j = 0;
  long long bounces = 1;
  while (true) {
    double trial_x = ((j + 1) * m - b) / slope;
    if (trial_x <= (i + 1) * n && trial_x >= i * n) {
      if (trial_x - i * n < 5 || (i + 1) * n - trial_x < 5) {
        cout << bounces << "\n";
        return 0;
      }
      if (comp(trial_x - i * n, p)) {
        break;
      }
      bounces++;
      j++;
    }

    double trial_y = slope * (i + 1) * n + b;
    if (trial_y <= (j + 1) * m && trial_y >= j * m) {
      if (trial_y - j * m < 5 || (j + 1) * m - trial_y < 5) {
        cout << bounces << "\n";
        return 0;
      }

      if (comp(trial_y - j * m, q)) {
        break;
      }
      bounces++;
      i++;
    }
  }

  cout << "0" << endl;
}
