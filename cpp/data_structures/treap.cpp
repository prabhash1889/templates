#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct ImplicitTreap {
  struct Node {
    ll val, sum, add = 0;
    uint32_t pri;
    int sz = 1;
    bool rev = 0;
    Node *l = 0, *r = 0;
    Node(ll v, uint32_t p) : val(v), sum(v), pri(p) {}
  };
  mt19937 rng{(uint32_t)chrono::steady_clock::now().time_since_epoch().count()};
  using P = Node *;
  P root = 0;
  int sz(P t) {
    return t ? t->sz : 0;
  }
  ll sum(P t) {
    return t ? t->sum : 0;
  }
  void pull(P t) {
    if (t)
      t->sz = 1 + sz(t->l) + sz(t->r), t->sum = t->val + sum(t->l) + sum(t->r);
  }
  void add(P t, ll v) {
    if (t)
      t->val += v, t->sum += v * t->sz, t->add += v;
  }
  void rev(P t) {
    if (t)
      t->rev ^= 1, swap(t->l, t->r);
  }
  void push(P t) {
    if (!t)
      return;
    if (t->rev)
      rev(t->l), rev(t->r), t->rev = 0;
    if (t->add)
      add(t->l, t->add), add(t->r, t->add), t->add = 0;
  }
  P node(ll v) {
    return new Node(v, rng());
  }
  void split(P t, int k, P &a, P &b) {
    if (!t) {
      a = b = 0;
      return;
    }
    push(t);
    if (sz(t->l) >= k)
      split(t->l, k, a, t->l), b = t;
    else
      split(t->r, k - sz(t->l) - 1, t->r, b), a = t;
    pull(t);
  }
  P merge(P a, P b) {
    if (!a || !b)
      return a ? a : b;
    if (a->pri > b->pri) {
      push(a);
      a->r = merge(a->r, b);
      pull(a);
      return a;
    }
    push(b);
    b->l = merge(a, b->l);
    pull(b);
    return b;
  }
  void build(vector<ll> a) {
    for (ll x : a)
      root = merge(root, node(x));
  }
  void range_add(int l, int r, ll v) {
    P a, b, c;
    split(root, r + 1, b, c);
    split(b, l, a, b);
    add(b, v);
    root = merge(merge(a, b), c);
  }
  void range_rev(int l, int r) {
    P a, b, c;
    split(root, r + 1, b, c);
    split(b, l, a, b);
    rev(b);
    root = merge(merge(a, b), c);
  }
  ll range_sum(int l, int r) {
    P a, b, c;
    split(root, r + 1, b, c);
    split(b, l, a, b);
    ll ans = sum(b);
    root = merge(merge(a, b), c);
    return ans;
  }
};
