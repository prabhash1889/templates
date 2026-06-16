#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INFLL = (1LL << 62);
struct Dijkstra {
  vector<ll> d;
  vector<int> par;
  vector<int> path(int t) {
    vector<int> p;
    if (d[t] >= INFLL / 2)
      return p;
    for (; t != -1; t = par[t])
      p.push_back(t);
    reverse(p.begin(), p.end());
    return p;
  }
};
Dijkstra dijkstra(const vector<vector<pair<int, ll>>> &g, vector<int> src) {
  int n = g.size();
  vector<ll> d(n, INFLL);
  vector<int> par(n, -1);
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  for (int s : src)
    d[s] = 0, pq.push({0, s});
  while (!pq.empty()) {
    auto [du, u] = pq.top();
    pq.pop();
    if (du != d[u])
      continue;
    for (auto [v, w] : g[u])
      if (d[v] > du + w)
        d[v] = du + w, par[v] = u, pq.push({d[v], v});
  }
  return {d, par};
}
