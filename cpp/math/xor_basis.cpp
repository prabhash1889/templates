#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct XorBasis {
  static const int LOG = 62;
  ll b[LOG + 1]{};
  int sz = 0;
  bool insert(ll x) {
    for (int i = LOG; i >= 0; i--)
      if (x >> i & 1) {
        if (!b[i]) {
          b[i] = x;
          sz++;
          return 1;
        }
        x ^= b[i];
      }
    return 0;
  }
  ll max_xor(ll x = 0) {
    for (int i = LOG; i >= 0; i--)
      x = max(x, x ^ b[i]);
    return x;
  }
  ll min_positive() {
    for (int i = 0; i <= LOG; i++)
      if (b[i])
        return b[i];
    return 0;
  }
};
