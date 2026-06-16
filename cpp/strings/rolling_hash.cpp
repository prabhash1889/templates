#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
struct RollingHash
{
  static ull base()
  {
    static ull b = chrono::steady_clock::now().time_since_epoch().count() * 2 + 1;
    return b;
  }
  vector<ull> h, p;
  RollingHash() {}
  RollingHash(const string &s)
  {
    build(s);
  }
  void build(const string &s)
  {
    int n = s.size();
    h.assign(n + 1, 0);
    p.assign(n + 1, 1);
    ull B = base();
    for (int i = 0; i < n; i++)
      h[i + 1] = h[i] * B + (unsigned char)s[i] + 1, p[i + 1] = p[i] * B;
  }
  ull get(int l, int r) const
  {
    return h[r] - h[l] * p[r - l];
  }
};
