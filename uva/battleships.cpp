#include <bits/stdc++.h>

using namespace std;

int n;
char grid[100][100];
bool visited[100][100];

void dfs(int x, int y) {
  if (visited[y][x])
    return;

  visited[y][x] = true;
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i == 0 && j == 0)
        continue;

      if (abs(i) == 1 && abs(j) == 1)
        continue;

      int new_x = x + i;
      int new_y = y + j;

      if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < n) {
        if (grid[new_y][new_x] == 'x' || grid[new_y][new_x] == '@') {
          dfs(new_x, new_y);
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int testcases;
  cin >> testcases;
  for (int tc = 1; tc <= testcases; tc++) {

    int num_ships = 0;
    memset(visited, 0, sizeof(visited));

    cin >> n;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> grid[i][j];
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (visited[i][j])
          continue;

        if (grid[i][j] == 'x') {
          dfs(j, i);
          num_ships++;
        }
      }
    }

    cout << "Case " << tc << ": " << num_ships << "\n";
  }
}
