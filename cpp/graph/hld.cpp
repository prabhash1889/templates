#include <bits/stdc++.h>
using namespace std;
struct HLD {
  int n, t = 0;
  vector<vector<int>> g;
  vector<int> par, dep, heavy, head, pos, sz;
  HLD(int n = 0) {
    init(n);
  }
  void init(int N) {
    n = N;
    g.assign(n, {});
    par.assign(n, -1);
    dep.assign(n, 0);
    heavy.assign(n, -1);
    head = pos = vector<int>(n);
    sz.assign(n, 1);
  }
  void add_edge(int u, int v) {
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int dfs(int u, int p) {
    par[u] = p;
    sz[u] = 1;
    int best = 0;
    for (int v : g[u])
      if (v != p) {
        dep[v] = dep[u] + 1;
        int s = dfs(v, u);
        sz[u] += s;
        if (s > best)
          best = s, heavy[u] = v;
      }
    return sz[u];
  }
  void decomp(int u, int h) {
    head[u] = h;
    pos[u] = t++;
    if (heavy[u] != -1)
      decomp(heavy[u], h);
    for (int v : g[u])
      if (v != par[u] && v != heavy[u])
        decomp(v, v);
  }
  void build(int r = 0) {
    dfs(r, -1);
    decomp(r, r);
  }
  template <class F> void path(int u, int v, F op, bool edge = 0) {
    while (head[u] != head[v]) {
      if (dep[head[u]] < dep[head[v]])
        swap(u, v);
      op(pos[head[u]], pos[u]);
      u = par[head[u]];
    }
    if (dep[u] > dep[v])
      swap(u, v);
    if (pos[u] + edge <= pos[v])
      op(pos[u] + edge, pos[v]);
  }
};
