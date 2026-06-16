#include <bits/stdc++.h>
using namespace std;
template <class Mint> struct Comb {
  vector<Mint> fact, ifact;
  Comb(int n = 0) {
    init(n);
  }
  void init(int n) {
    fact.assign(n + 1, 1);
    ifact.assign(n + 1, 1);
    for (int i = 1; i <= n; i++)
      fact[i] = fact[i - 1] * i;
    ifact[n] = inv(fact[n]);
    for (int i = n; i; i--)
      ifact[i - 1] = ifact[i] * i;
  }
  Mint C(int n, int k) {
    return k < 0 || k > n ? 0 : fact[n] * ifact[k] * ifact[n - k];
  }
  Mint P(int n, int k) {
    return k < 0 || k > n ? 0 : fact[n] * ifact[n - k];
  }
};
