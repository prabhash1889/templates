#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct LazySeg {
  struct N {
    ll sum = 0, mn = 0, mx = 0;
  };
  struct Tag {
    ll add = 0, set = 0;
    bool has = 0;
  };
  int n;
  vector<N> st;
  vector<Tag> lz;
  LazySeg(int n = 0) {
    if (n)
      init(n);
  }
  void init(int N) {
    n = N;
    st.assign(4 * n, {});
    lz.assign(4 * n, {});
  }
  N merge(N a, N b) {
    return {a.sum + b.sum, min(a.mn, b.mn), max(a.mx, b.mx)};
  }
  void apply_set(int p, int l, int r, ll v) {
    st[p] = {v * (r - l + 1), v, v};
    lz[p] = {0, v, 1};
  }
  void apply_add(int p, int l, int r, ll v) {
    st[p].sum += v * (r - l + 1);
    st[p].mn += v;
    st[p].mx += v;
    if (lz[p].has)
      lz[p].set += v;
    else
      lz[p].add += v;
  }
  void push(int p, int l, int r) {
    if (l == r) {
      lz[p] = {};
      return;
    }
    int m = (l + r) / 2;
    if (lz[p].has)
      apply_set(p << 1, l, m, lz[p].set), apply_set(p << 1 | 1, m + 1, r, lz[p].set);
    if (lz[p].add)
      apply_add(p << 1, l, m, lz[p].add), apply_add(p << 1 | 1, m + 1, r, lz[p].add);
    lz[p] = {};
  }
  void build(vector<ll> &a, int p, int l, int r) {
    if (l == r) {
      st[p] = {a[l], a[l], a[l]};
      return;
    }
    int m = (l + r) / 2;
    build(a, p << 1, l, m);
    build(a, p << 1 | 1, m + 1, r);
    st[p] = merge(st[p << 1], st[p << 1 | 1]);
  }
  void build(vector<ll> a) {
    init(a.size());
    build(a, 1, 0, n - 1);
  }
  void add(int L, int R, ll v, int p = 1, int l = 0, int r = -1) {
    if (r < 0)
      r = n - 1;
    if (R < l || r < L)
      return;
    if (L <= l && r <= R)
      return apply_add(p, l, r, v);
    push(p, l, r);
    int m = (l + r) / 2;
    add(L, R, v, p << 1, l, m);
    add(L, R, v, p << 1 | 1, m + 1, r);
    st[p] = merge(st[p << 1], st[p << 1 | 1]);
  }
  void setv(int L, int R, ll v, int p = 1, int l = 0, int r = -1) {
    if (r < 0)
      r = n - 1;
    if (R < l || r < L)
      return;
    if (L <= l && r <= R)
      return apply_set(p, l, r, v);
    push(p, l, r);
    int m = (l + r) / 2;
    setv(L, R, v, p << 1, l, m);
    setv(L, R, v, p << 1 | 1, m + 1, r);
    st[p] = merge(st[p << 1], st[p << 1 | 1]);
  }
  N query(int L, int R, int p = 1, int l = 0, int r = -1) {
    if (r < 0)
      r = n - 1;
    if (L <= l && r <= R)
      return st[p];
    push(p, l, r);
    int m = (l + r) / 2;
    if (R <= m)
      return query(L, R, p << 1, l, m);
    if (L > m)
      return query(L, R, p << 1 | 1, m + 1, r);
    return merge(query(L, R, p << 1, l, m), query(L, R, p << 1 | 1, m + 1, r));
  }
};
