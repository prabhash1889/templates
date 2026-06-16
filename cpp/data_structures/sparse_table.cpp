#include <bits/stdc++.h>
using namespace std;
template <class T, class F> struct SparseTable {
  int n, K;
  F f;
  vector<vector<T>> st;
  vector<int> lg;
  SparseTable() {}
  SparseTable(vector<T> a, F f) : f(f) {
    build(a);
  }
  void build(vector<T> a) {
    n = a.size();
    K = n ? __lg(n) + 1 : 1;
    st.assign(K, vector<T>(n));
    if (n)
      st[0] = a;
    for (int k = 1; k < K; k++)
      for (int i = 0; i + (1 << k) <= n; i++)
        st[k][i] = f(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
    lg.assign(n + 1, 0);
    for (int i = 2; i <= n; i++)
      lg[i] = lg[i / 2] + 1;
  }
  T query(int l, int r) {
    int k = lg[r - l + 1];
    return f(st[k][l], st[k][r - (1 << k) + 1]);
  }
};
