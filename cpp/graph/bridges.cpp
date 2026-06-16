#include <bits/stdc++.h>
using namespace std;
struct LowLink {
  int n, t = 0;
  vector<vector<pair<int, int>>> g;
  vector<int> tin, low, is_art;
  vector<pair<int, int>> bridges;
  LowLink(int n = 0) : n(n), g(n) {}
  void add_edge(int u, int v, int id) {
    g[u].push_back({v, id});
    g[v].push_back({u, id});
  }
  void dfs(int u, int pe = -1) {
    tin[u] = low[u] = t++;
    int ch = 0;
    for (auto [v, id] : g[u])
      if (id != pe) {
        if (tin[v] == -1) {
          ch++;
          dfs(v, id);
          low[u] = min(low[u], low[v]);
          if (low[v] > tin[u])
            bridges.push_back({u, v});
          if (pe != -1 && low[v] >= tin[u])
            is_art[u] = 1;
        } else
          low[u] = min(low[u], tin[v]);
      }
    if (pe == -1 && ch > 1)
      is_art[u] = 1;
  }
  void build() {
    tin.assign(n, -1);
    low.assign(n, 0);
    is_art.assign(n, 0);
    for (int i = 0; i < n; i++)
      if (tin[i] == -1)
        dfs(i);
  }
};
