#include <bits/stdc++.h>

using namespace std;

string name = "IEHOVA#";
char grid[8][8];
int m, n;
vector<string> path;

char get_grid(int x, int y) {
  if (x >= 0 && x < n && y >= 0 && y < m) {
    return grid[y][x];
  } else {
    return '!';
  }
}
bool dfs(int x, int y, int next_char) {
  if (grid[y][x] == '#') {
    return true;
  }

  // forth
  if (get_grid(x, y - 1) == name[next_char]) {
    if (dfs(x, y - 1, next_char + 1)) {
      path.push_back("forth");
      return true;
    }
  }

  // left
  if (get_grid(x - 1, y) == name[next_char]) {
    if (dfs(x - 1, y, next_char + 1)) {
      path.push_back("left");
      return true;
    }
  }

  // right
  if (get_grid(x + 1, y) == name[next_char]) {
    if (dfs(x + 1, y, next_char + 1)) {
      path.push_back("right");
      return true;
    }
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int test_cases;
  cin >> test_cases;

  for (int tc = 0; tc < test_cases; tc++) {
    cin >> m >> n;
    path.clear();
    int start_x, start_y;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        char c;
        cin >> c;
        grid[i][j] = c;
        if (grid[i][j] == '@') {
          start_x = j;
          start_y = i;
        }
      }
    }

    dfs(start_x, start_y, 0);
    reverse(path.begin(), path.end());
    for (int a = 0; a < path.size() - 1; a++) {
      cout << path[a] << " ";
    }

    cout << path[path.size() - 1] << "\n";
  }
}
