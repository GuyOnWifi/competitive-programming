#include <bits/stdc++.h>
using namespace std;

vector<int> graph[101];
int n, m;
bool visited[101];
bool is_cycle = false;
int num_nodes = 0;

void dfs(int id, int parent) {
  if (visited[id]) {
    is_cycle = true;
    return;
  };
  num_nodes++;
  visited[id] = true;

  for (auto x : graph[id]) {
    if (x == parent)
      continue;
    dfs(x, id);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  int odd_cycles = 0;
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      num_nodes = 0;
      is_cycle = false;
      dfs(i, -1);

      if (is_cycle && num_nodes % 2 == 1) {
        odd_cycles++;
      }
    }
  }

  if ((n - odd_cycles) % 2 == 1) {
    odd_cycles++;
  }
  cout << odd_cycles << endl;
}
