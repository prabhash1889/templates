#include <bits/stdc++.h>
using namespace std;
struct Centroid {
  int n;
  vector<vector<int>> g;
  vector<int> sub, dead, par, best;
  vector<vector<pair<int, int>>> path;
  Centroid(int n = 0) {
    init(n);
  }
  void init(int N) {
    n = N;
    g.assign(n, {});
    sub = dead = vector<int>(n);
    par.assign(n, -1);
    best.assign(n, 1e9);
    path.assign(n, {});
  }
  void add_edge(int u, int v) {
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int dfs_sz(int u, int p) {
    sub[u] = 1;
    for (int v : g[u])
      if (v != p && !dead[v])
        sub[u] += dfs_sz(v, u);
    return sub[u];
  }
  int cen(int u, int p, int tot) {
    for (int v : g[u])
      if (v != p && !dead[v] && sub[v] > tot / 2)
        return cen(v, u, tot);
    return u;
  }
  void collect(int u, int p, int d, int c) {
    path[u].push_back({c, d});
    for (int v : g[u])
      if (v != p && !dead[v])
        collect(v, u, d + 1, c);
  }
  void build(int u = 0, int p = -1) {
    int tot = dfs_sz(u, -1), c = cen(u, -1, tot);
    par[c] = p;
    dead[c] = 1;
    collect(c, -1, 0, c);
    for (int v : g[c])
      if (!dead[v])
        build(v, c);
  }
  void update(int u) {
    for (auto [c, d] : path[u])
      best[c] = min(best[c], d);
  }
  int query(int u) {
    int ans = 1e9;
    for (auto [c, d] : path[u])
      ans = min(ans, best[c] + d);
    return ans;
  }
};
