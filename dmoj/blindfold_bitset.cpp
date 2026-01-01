#include <bits/stdc++.h>

using namespace std;
const int MAX_SIZE = 30000;

char grid[375][80];

bitset<MAX_SIZE> pos[4];
bitset<MAX_SIZE> grid_mask;
bitset<MAX_SIZE> col_0_mask;
bitset<MAX_SIZE> col_n_mask;

int r, c;

int get_idx(int x, int y) { return x + y * c; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> r >> c;
  col_0_mask = ~col_0_mask;
  col_n_mask = ~col_n_mask;

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == '.') {
        grid_mask.set(get_idx(j, i), 1);
      }
    }
  }

  for (int i = 0; i < r; i++) {
    col_0_mask.set(get_idx(0, i), false);
    col_n_mask.set(get_idx(c - 1, i), false);
  }

  for (int p = 0; p < 4; p++) {
    pos[p] = grid_mask;
  }

  int m;
  cin >> m;

  for (int i = 0; i < m; i++) {
    char mov;
    cin >> mov;

    if (mov == 'F') {
      pos[0] = (pos[0] >> c) & grid_mask;
      pos[1] = (pos[1] << 1) & col_0_mask & grid_mask;
      pos[2] = (pos[2] << c) & grid_mask;
      pos[3] = (pos[3] >> 1) & col_n_mask & grid_mask;
    } else if (mov == 'R') {
      bitset<MAX_SIZE> tmp = pos[3];
      pos[3] = pos[2];
      pos[2] = pos[1];
      pos[1] = pos[0];
      pos[0] = tmp;
    } else if (mov == 'L') {
      bitset<MAX_SIZE> tmp = pos[0];
      pos[0] = pos[1];
      pos[1] = pos[2];
      pos[2] = pos[3];
      pos[3] = tmp;
    }
  }

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      bool possible = false;
      for (int p = 0; p < 4; p++) {
        if (pos[p][get_idx(j, i)]) {
          possible = true;
        }
      }

      if (possible) {
        cout << '*';
      } else {
        cout << grid[i][j];
      }
    }
    cout << "\n";
  }
}
