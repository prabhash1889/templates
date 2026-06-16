#include <bits/stdc++.h>
using namespace std;
struct LCA
{
  int n, LOG, t = 0;
  vector<vector<int>> g, up;
  vector<int> tin, tout, dep;
  LCA(int n = 0)
  {
    init(n);
  }
  void init(int N)
  {
    n = N;
    LOG = n ? __lg(n) + 1 : 1;
    g.assign(n, {});
    up.assign(LOG, vector<int>(n));
    tin = tout = dep = vector<int>(n);
  }
  void add_edge(int u, int v)
  {
    g[u].push_back(v);
    g[v].push_back(u);
  }
  void dfs(int u, int p)
  {
    tin[u] = t++;
    up[0][u] = p;
    for (int k = 1; k < LOG; k++)
      up[k][u] = up[k - 1][up[k - 1][u]];
    for (int v : g[u])
      if (v != p)
        dep[v] = dep[u] + 1, dfs(v, u);
    tout[u] = t++;
  }
  void build(int r = 0)
  {
    dfs(r, r);
  }
  bool anc(int u, int v) const
  {
    return tin[u] <= tin[v] && tout[v] <= tout[u];
  }
  int lca(int u, int v) const
  {
    if (anc(u, v))
      return u;
    if (anc(v, u))
      return v;
    for (int k = LOG - 1; k >= 0; k--)
      if (!anc(up[k][u], v))
        u = up[k][u];
    return up[0][u];
  }
  int dist(int u, int v) const
  {
    int w = lca(u, v);
    return dep[u] + dep[v] - 2 * dep[w];
  }
};
