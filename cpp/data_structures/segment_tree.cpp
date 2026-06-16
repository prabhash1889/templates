#include <bits/stdc++.h>
using namespace std;
template <class T, class Merge>
struct SegTree
{
  int n;
  T id;
  Merge merge;
  vector<T> st;
  SegTree(int n = 0, T id = T{}, Merge m = Merge()) : id(id), merge(m)
  {
    if (n)
      init(n);
  }
  void init(int N)
  {
    n = 1;
    while (n < N)
      n <<= 1;
    st.assign(2 * n, id);
  }
  void build(const vector<T> &a)
  {
    init(a.size());
    for (int i = 0; i < (int)a.size(); i++)
      st[n + i] = a[i];
    for (int i = n - 1; i; i--)
      st[i] = merge(st[i << 1], st[i << 1 | 1]);
  }
  void setPoint(int p, T v)
  {
    for (st[p += n] = v, p >>= 1; p; p >>= 1)
      st[p] = merge(st[p << 1], st[p << 1 | 1]);
  }
  T query(int l, int r)
  {
    T L = id, R = id;
    for (l += n, r += n; l <= r; l >>= 1, r >>= 1)
    {
      if (l & 1)
        L = merge(L, st[l++]);
      if (!(r & 1))
        R = merge(st[r--], R);
    }
    return merge(L, R);
  }
};
