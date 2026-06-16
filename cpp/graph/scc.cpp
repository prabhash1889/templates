#include <bits/stdc++.h>
using namespace std;
struct SCC
{
  int n, t = 0, c = 0;
  vector<vector<int>> g;
  vector<int> tin, low, comp, st, in;
  SCC(int n = 0) : n(n), g(n) {}
  void add_edge(int u, int v)
  {
    g[u].push_back(v);
  }
  void dfs(int u)
  {
    tin[u] = low[u] = t++;
    st.push_back(u);
    in[u] = 1;
    for (int v : g[u])
    {
      if (tin[v] == -1)
        dfs(v), low[u] = min(low[u], low[v]);
      else if (in[v])
        low[u] = min(low[u], tin[v]);
    }
    if (low[u] == tin[u])
    {
      while (1)
      {
        int v = st.back();
        st.pop_back();
        in[v] = 0;
        comp[v] = c;
        if (v == u)
          break;
      }
      c++;
    }
  }
  int build()
  {
    tin.assign(n, -1);
    low.assign(n, 0);
    comp.assign(n, -1);
    in.assign(n, 0);
    for (int i = 0; i < n; i++)
      if (tin[i] == -1)
        dfs(i);
    return c;
  }
};
