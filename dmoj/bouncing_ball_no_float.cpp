#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long n, m, p, q;
  cin >> n >> m >> p >> q;

  long long dx = n - p;
  long long dy = q;
  long long b_mult_dx = -dy * p;

  long long i = 1;
  long long j = 0;
  long long bounces = 1;
  while (true) {
    long long trial_x_mult_dy = ((j + 1) * m * dx - b_mult_dx);
    if (trial_x_mult_dy <= (i + 1) * n * dy && trial_x_mult_dy >= i * n * dy) {
      if (trial_x_mult_dy - i * n * dy < 5 * dy ||
          (i + 1) * n * dy - trial_x_mult_dy < 5 * dy) {
        cout << bounces << "\n";
        return 0;
      }
      if (trial_x_mult_dy - i * n * dy == p * dy) {
        break;
      }
      bounces++;
      j++;
    }

    long long trial_y_mult_dx = dy * (i + 1) * n + b_mult_dx;
    if (trial_y_mult_dx <= (j + 1) * m * dx && trial_y_mult_dx >= j * m * dx) {
      if (trial_y_mult_dx - j * m * dx < 5 * dx ||
          (j + 1) * m * dx - trial_y_mult_dx < 5 * dx) {
        cout << bounces << "\n";
        return 0;
      }
      if (trial_y_mult_dx - j * m * dx == q * dx) {
        break;
      }
      bounces++;
      i++;
    }
  }

  cout << "0" << endl;
}
