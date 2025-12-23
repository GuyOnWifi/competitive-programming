// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=288

#include <cstring>
#include <iostream>
using namespace std;

int count = 0;
bool visited[25][25];
bool pixels[25][25];
void dfs(int dim, int x, int y, bool counting) {
  if (x < 0 || y < 0 || y >= dim || x >= dim) {
    return;
  }
  if (visited[x][y])
    return;

  visited[x][y] = true;

  if (pixels[y][x] == 1) {
    if (!counting) {
      count++;
      counting = true;
    }
    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        if (i == 0 && j == 0)
          continue;
        dfs(dim, x + i, y + j, counting);
      }
    }
  }
}

int main() {
  int dim;
  int img = 1;
  while (cin >> dim) {
    count = 0;
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < dim; i++) {
      string s;
      cin >> s;

      for (int j = 0; j < dim; j++) {
        pixels[i][j] = s[j] == '1';
      }
    }

    for (int i = 0; i < dim; i++) {
      for (int j = 0; j < dim; j++) {
        dfs(dim, j, i, false);
      }
    }

    cout << "Image number " << img << " contains " << count << " war eagles."
         << "\n";
    img++;
  }
}
