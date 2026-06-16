#include <bits/stdc++.h>
using namespace std;
vector<int> bfs(const vector<vector<int>> &g, vector<int> src) {
  int n = g.size();
  vector<int> d(n, -1);
  queue<int> q;
  for (int s : src)
    d[s] = 0, q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : g[u])
      if (d[v] < 0)
        d[v] = d[u] + 1, q.push(v);
  }
  return d;
}
vector<int> zero_one_bfs(const vector<vector<pair<int, int>>> &g, int s) {
  int n = g.size(), INF = 1e9;
  vector<int> d(n, INF);
  deque<int> q;
  d[s] = 0;
  q.push_front(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop_front();
    for (auto [v, w] : g[u])
      if (d[v] > d[u] + w) {
        d[v] = d[u] + w;
        (w ? q.push_back(v) : q.push_front(v));
      }
  }
  return d;
}
