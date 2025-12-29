#include <bits/stdc++.h>

using namespace std;

vector<int> graph[1001];
bool visited[1001];

void bfs() {
  queue<int> q;

  q.push(0);
  visited[0] = true;

  while (!q.empty()) {
    int el = q.front();
    q.pop();

    for (auto x : graph[el]) {
      if (visited[x])
        continue;
      visited[x] = true;
      q.push(x);
    }
  }
}

int main() {}
