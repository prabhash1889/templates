#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll LICH_INF = (1LL << 62);
struct LiChao {
  struct Line {
    ll m, b;
    ll get(ll x) const {
      return m * x + b;
    }
  };
  struct Node {
    Line ln;
    Node *l = 0, *r = 0;
    Node(Line ln) : ln(ln) {}
  };
  ll lo, hi;
  Node *root = 0;
  LiChao(ll l, ll r) : lo(l), hi(r) {}
  void add(Line nw) {
    add(root, lo, hi, nw);
  }
  void add(Node *&t, ll l, ll r, Line nw) {
    if (!t) {
      t = new Node(nw);
      return;
    }
    ll m = (l + r) / 2;
    bool lef = nw.get(l) < t->ln.get(l), mid = nw.get(m) < t->ln.get(m);
    if (mid)
      swap(nw, t->ln);
    if (l == r)
      return;
    if (lef != mid)
      add(t->l, l, m, nw);
    else
      add(t->r, m + 1, r, nw);
  }
  ll query(ll x) {
    return query(root, lo, hi, x);
  }
  ll query(Node *t, ll l, ll r, ll x) {
    if (!t)
      return LICH_INF;
    ll ans = t->ln.get(x);
    if (l == r)
      return ans;
    ll m = (l + r) / 2;
    return min(ans, x <= m ? query(t->l, l, m, x) : query(t->r, m + 1, r, x));
  }
};
