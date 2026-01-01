// CCC '02 S3 - Blindfold

#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

char grid[376][81];
char moves[30001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int r, c;
  cin >> r >> c;

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> grid[i][j];
    }
  }

  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> moves[i];
  }

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (grid[i][j] == 'X')
        continue;
      // 0 N, 1 E, 2 S, 3 W,
      for (int d = 0; d < 4; d++) {
        bool sim = true;
        int x = j;
        int y = i;
        int dir = d;
        for (int s = 0; s < m; s++) {
          if (moves[s] == 'F') {
            if (dir == 0) {
              y--;
            } else if (dir == 1) {
              x++;
            } else if (dir == 2) {
              y++;
            } else if (dir == 3) {
              x--;
            }
          } else if (moves[s] == 'R') {
            dir = (dir + 1) % 4;
          } else if (moves[s] == 'L') {
            dir = (dir + 3) % 4;
          }

          if (x < 0 || x >= c || y < 0 || y >= r) {
            sim = false;
            break;
          }
          if (grid[y][x] == 'X') {
            sim = false;
            break;
          }
        }

        if (sim) {
          grid[y][x] = '*';
        }
      }
    }
  }

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cout << grid[i][j];
    }
    cout << "\n";
  }
}
