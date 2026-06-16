#include <bits/stdc++.h>
using namespace std;
struct Sieve {
  int n;
  vector<int> pr, spf, phi, mu;
  Sieve(int n = 0) {
    if (n)
      init(n);
  }
  void init(int N) {
    n = N;
    spf.assign(n + 1, 0);
    phi.assign(n + 1, 0);
    mu.assign(n + 1, 0);
    phi[1] = 1;
    mu[1] = 1;
    for (int i = 2; i <= n; i++) {
      if (!spf[i])
        spf[i] = i, pr.push_back(i), phi[i] = i - 1, mu[i] = -1;
      for (int p : pr) {
        long long x = 1LL * p * i;
        if (x > n || p > spf[i])
          break;
        spf[x] = p;
        if (p == spf[i]) {
          phi[x] = phi[i] * p;
          mu[x] = 0;
          break;
        }
        phi[x] = phi[i] * (p - 1);
        mu[x] = -mu[i];
      }
    }
  }
  vector<pair<int, int>> factor(int x) {
    vector<pair<int, int>> f;
    while (x > 1) {
      int p = spf[x], c = 0;
      while (x % p == 0)
        x /= p, c++;
      f.push_back({p, c});
    }
    return f;
  }
};
