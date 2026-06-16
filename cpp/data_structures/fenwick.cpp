#include <bits/stdc++.h>
using namespace std;
template <class T>
struct Fenwick
{
  int n;
  vector<T> bit;
  Fenwick(int n = 0)
  {
    init(n);
  }
  void init(int n_)
  {
    n = n_;
    bit.assign(n + 1, T{});
  }
  void add(int i, T v)
  {
    for (++i; i <= n; i += i & -i)
      bit[i] += v;
  }
  T sumPrefix(int i) const
  {
    T r{};
    for (++i; i > 0; i -= i & -i)
      r += bit[i];
    return r;
  }
  T sumRange(int l, int r) const
  {
    return l > r ? T{} : sumPrefix(r) - (l ? sumPrefix(l - 1) : T{});
  }
  int kth(T k) const
  {
    int idx = 0;
    for (int pw = 1 << __lg(max(1, n)); pw; pw >>= 1)
    {
      int ni = idx + pw;
      if (ni <= n && bit[ni] < k)
        idx = ni, k -= bit[ni];
    }
    return idx;
  }
};
template <class T>
struct RangeFenwick
{
  int n;
  Fenwick<T> b1, b2;
  RangeFenwick(int n = 0)
  {
    init(n);
  }
  void init(int n_)
  {
    n = n_;
    b1.init(n);
    b2.init(n);
  }
  void addRange(int l, int r, T v)
  {
    b1.add(l, v);
    if (r + 1 < n)
      b1.add(r + 1, -v);
    b2.add(l, v * l);
    if (r + 1 < n)
      b2.add(r + 1, -v * (r + 1));
  }
  T pref(int i) const
  {
    return b1.sumPrefix(i) * (i + 1) - b2.sumPrefix(i);
  }
  T sum(int l, int r) const
  {
    return pref(r) - (l ? pref(l - 1) : T{});
  }
};
