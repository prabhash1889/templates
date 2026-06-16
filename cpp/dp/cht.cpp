#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Line {
  mutable ll k, m, p;
  bool operator<(const Line &o) const {
    return k < o.k;
  }
  bool operator<(ll x) const {
    return p < x;
  }
};
struct LineContainer : multiset<Line, less<>> {
  static const ll INF = LLONG_MAX;
  ll div(ll a, ll b) {
    if (b < 0)
      a = -a, b = -b;
    return a >= 0 ? a / b : -((-a + b - 1) / b);
  }
  bool isect(iterator x, iterator y) {
    if (y == end())
      return x->p = INF, 0;
    if (x->k == y->k)
      x->p = x->m > y->m ? INF : -INF;
    else
      x->p = div(y->m - x->m, x->k - y->k);
    return x->p >= y->p;
  }
  void add_line(ll k, ll m) {
    auto z = insert({k, m, 0}), y = z++, x = y;
    while (isect(y, z))
      z = erase(z);
    if (x != begin() && isect(--x, y))
      isect(x, y = erase(y));
    while ((y = x) != begin() && (--x)->p >= y->p)
      isect(x, erase(y));
  }
  ll query(ll x) {
    auto l = *lower_bound(x);
    return l.k * x + l.m;
  }
};
struct MonotoneCHTMin {
  struct L {
    ll m, b;
    ll get(ll x) const {
      return m * x + b;
    }
  };
  deque<L> q;
  bool bad(L a, L b, L c) {
    return (__int128)(b.b - a.b) * (a.m - c.m) >= (__int128)(c.b - a.b) * (a.m - b.m);
  }
  void add(ll m, ll b) {
    L x{m, b};
    while (q.size() >= 2 && bad(q[q.size() - 2], q.back(), x))
      q.pop_back();
    q.push_back(x);
  }
  ll query(ll x) {
    while (q.size() >= 2 && q[0].get(x) >= q[1].get(x))
      q.pop_front();
    return q[0].get(x);
  }
};
