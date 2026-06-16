#include <bits/stdc++.h>
using namespace std;
struct DSU {
  vector<int> p, sz;
  int comps;
  DSU(int n = 0) {
    init(n);
  }
  void init(int n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
    sz.assign(n, 1);
    comps = n;
  }
  int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
  }
  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b)
      return 0;
    if (sz[a] < sz[b])
      swap(a, b);
    p[b] = a;
    sz[a] += sz[b];
    --comps;
    return 1;
  }
  int size(int x) {
    return sz[find(x)];
  }
};
struct RollbackDSU {
  vector<int> p, sz;
  vector<pair<int, int>> hist;
  int comps;
  RollbackDSU(int n = 0) {
    init(n);
  }
  void init(int n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
    sz.assign(n, 1);
    hist.clear();
    comps = n;
  }
  int find(int x) const {
    while (p[x] != x)
      x = p[x];
    return x;
  }
  int snapshot() const {
    return hist.size();
  }
  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) {
      hist.push_back({-1, -1});
      return 0;
    }
    if (sz[a] < sz[b])
      swap(a, b);
    hist.push_back({b, a});
    p[b] = a;
    sz[a] += sz[b];
    --comps;
    return 1;
  }
  void rollback(int snap) {
    while ((int)hist.size() > snap) {
      auto [b, a] = hist.back();
      hist.pop_back();
      if (b == -1)
        continue;
      p[b] = b;
      sz[a] -= sz[b];
      ++comps;
    }
  }
};
