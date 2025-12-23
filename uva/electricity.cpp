#include <iostream>

using namespace std;

bool is_consecutive(int d1, int m1, int y1, int d2, int m2, int y2) {
  if (y2 == y1 + 1) {
    return d1 == 31 && m1 == 12 && d2 == 1 && m2 == 1;
  }

  if (y2 != y1)
    return false;

  if (d1 == 31 &&
      (m1 == 1 || m1 == 3 || m1 == 5 || m1 == 7 || m1 == 8 || m1 == 10)) {
    if (d2 == 1 && m2 == m1 + 1) {
      return true;
    } else {
      return false;
    }
  }

  if (d1 == 30 && (m1 == 4 || m1 == 6 || m1 == 9 || m1 == 11)) {
    if (d2 == 1 && m2 == m1 + 1) {
      return true;
    } else {
      return false;
    }
  }

  if (m1 == 2) {
    bool leap_year = y1 % 400 == 0 || (y1 % 4 == 0 && y1 % 100 != 0);
    if (leap_year && d1 == 29 && d2 == 1 && m2 == 3) {
      return true;
    } else if (!leap_year && d1 == 28 && d2 == 1 && m2 == 3) {
      return true;
    }
  }

  if (m1 != m2)
    return false;

  if (d2 == d1 + 1)
    return true;

  return false;
}

int main() {

  int N;
  while (cin >> N && N != 0) {
    int prev_d, prev_m, prev_y, prev_cons;
    cin >> prev_d >> prev_m >> prev_y >> prev_cons;

    int num_days = 0;
    int consump = 0;
    for (int i = 1; i < N; i++) {
      int d, m, y, cons;
      cin >> d >> m >> y >> cons;

      if (is_consecutive(prev_d, prev_m, prev_y, d, m, y)) {
        num_days++;
        consump += (cons - prev_cons);
      }

      prev_d = d;
      prev_m = m;
      prev_y = y;
      prev_cons = cons;
    }
    cout << num_days << " " << consump << "\n";
  }
}
