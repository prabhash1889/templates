#include <bits/stdc++.h>
using namespace std;
template <class C>
struct Dinic
{
  struct E
  {
    int to, rev;
    C cap;
  };
  int n;
  vector<vector<E>> g;
  vector<int> lvl, it;
  Dinic(int n = 0) : n(n), g(n) {}
  void add_edge(int v, int to, C cap)
  {
    E a{to, (int)g[to].size(), cap}, b{v, (int)g[v].size(), 0};
    g[v].push_back(a);
    g[to].push_back(b);
  }
  bool bfs(int s, int t)
  {
    lvl.assign(n, -1);
    queue<int> q;
    lvl[s] = 0;
    q.push(s);
    while (!q.empty())
    {
      int v = q.front();
      q.pop();
      for (auto &e : g[v])
        if (e.cap > 0 && lvl[e.to] < 0)
          lvl[e.to] = lvl[v] + 1, q.push(e.to);
    }
    return lvl[t] >= 0;
  }
  C dfs(int v, int t, C f)
  {
    if (v == t)
      return f;
    for (int &i = it[v]; i < (int)g[v].size(); i++)
    {
      E &e = g[v][i];
      if (e.cap > 0 && lvl[e.to] == lvl[v] + 1)
      {
        C ret = dfs(e.to, t, min(f, e.cap));
        if (ret)
        {
          e.cap -= ret;
          g[e.to][e.rev].cap += ret;
          return ret;
        }
      }
    }
    return 0;
  }
  C flow(int s, int t)
  {
    C ans = 0, INF = numeric_limits<C>::max() / 4;
    while (bfs(s, t))
    {
      it.assign(n, 0);
      while (C f = dfs(s, t, INF))
        ans += f;
    }
    return ans;
  }
};
