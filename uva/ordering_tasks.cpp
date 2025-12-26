#include <bits/stdc++.h>

using namespace std;

vector<int> tasks[101];
bool vis[101];
vector<int> order;

void dfs(int x) {
  if (vis[x])
    return;
  vis[x] = true;

  for (auto next : tasks[x]) {
    dfs(next);
  }
  order.push_back(x);
  return;
}

int main() {
  int n, m;

  while (cin >> n >> m && n != 0) {
    for (int i = 0; i <= 100; i++) {
      tasks[i].clear();
    }
    memset(vis, 0, sizeof(vis));
    order.clear();

    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      // REVERSE THE OPRDER
      tasks[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
      dfs(i);
    }

    for (int idx = 0; idx < (int)order.size() - 1; idx++) {
      cout << order[idx] << " ";
    }
    cout << order[order.size() - 1] << "\n";
  }
}
