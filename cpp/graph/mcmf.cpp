#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MCMF_INF = (1LL << 62);
struct MCMF {
  struct E {
    int to, rev;
    ll cap, cost;
  };
  int n;
  vector<vector<E>> g;
  MCMF(int n = 0) : n(n), g(n) {}
  void add_edge(int v, int to, ll cap, ll cost) {
    E a{to, (int)g[to].size(), cap, cost}, b{v, (int)g[v].size(), 0, -cost};
    g[v].push_back(a);
    g[to].push_back(b);
  }
  pair<ll, ll> flow(int s, int t, ll need = MCMF_INF) {
    ll fl = 0, cost = 0;
    vector<ll> pot(n), d(n);
    vector<int> pv(n), pe(n);
    while (fl < need) {
      fill(d.begin(), d.end(), MCMF_INF);
      priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
      d[s] = 0;
      pq.push({0, s});
      while (!pq.empty()) {
        auto [du, u] = pq.top();
        pq.pop();
        if (du != d[u])
          continue;
        for (int i = 0; i < (int)g[u].size(); i++) {
          auto &e = g[u][i];
          if (e.cap && d[e.to] > du + e.cost + pot[u] - pot[e.to])
            d[e.to] = du + e.cost + pot[u] - pot[e.to], pv[e.to] = u, pe[e.to] = i,
            pq.push({d[e.to], e.to});
        }
      }
      if (d[t] == MCMF_INF)
        break;
      for (int i = 0; i < n; i++)
        if (d[i] < MCMF_INF)
          pot[i] += d[i];
      ll add = need - fl;
      for (int v = t; v != s; v = pv[v])
        add = min(add, g[pv[v]][pe[v]].cap);
      for (int v = t; v != s; v = pv[v]) {
        auto &e = g[pv[v]][pe[v]];
        e.cap -= add;
        g[v][e.rev].cap += add;
        cost += add * e.cost;
      }
      fl += add;
    }
    return {fl, cost};
  }
};
