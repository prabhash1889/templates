#include <bits/stdc++.h>
using namespace std;
using u64 = uint64_t;
using u128 = __uint128_t;
u64 mul(u64 a, u64 b, u64 m) {
  return (u128)a * b % m;
}
u64 mpow(u64 a, u64 e, u64 m) {
  u64 r = 1;
  while (e) {
    if (e & 1)
      r = mul(r, a, m);
    a = mul(a, a, m);
    e >>= 1;
  }
  return r;
}
bool isPrime64(u64 n) {
  if (n < 2)
    return 0;
  for (u64 p : {2ULL, 3ULL, 5ULL, 7ULL, 11ULL, 13ULL, 17ULL, 19ULL, 23ULL, 29ULL, 31ULL, 37ULL})
    if (n % p == 0)
      return n == p;
  u64 d = n - 1, s = 0;
  while (!(d & 1))
    d >>= 1, s++;
  for (u64 a : {2ULL, 325ULL, 9375ULL, 28178ULL, 450775ULL, 9780504ULL, 1795265022ULL}) {
    if (a % n == 0)
      continue;
    u64 x = mpow(a, d, n);
    if (x == 1 || x == n - 1)
      continue;
    bool ok = 0;
    for (u64 r = 1; r < s; r++) {
      x = mul(x, x, n);
      if (x == n - 1) {
        ok = 1;
        break;
      }
    }
    if (!ok)
      return 0;
  }
  return 1;
}
mt19937_64 frng(chrono::steady_clock::now().time_since_epoch().count());
u64 rho(u64 n) {
  if (n % 2 == 0)
    return 2;
  while (1) {
    u64 c = uniform_int_distribution<u64>(1, n - 1)(frng),
        x = uniform_int_distribution<u64>(0, n - 1)(frng), y = x, d = 1;
    auto f = [&](u64 v) { return (mul(v, v, n) + c) % n; };
    while (d == 1)
      x = f(x), y = f(f(y)), d = gcd(x > y ? x - y : y - x, n);
    if (d < n)
      return d;
  }
}
void factor(u64 n, vector<u64> &v) {
  if (n == 1)
    return;
  if (isPrime64(n)) {
    v.push_back(n);
    return;
  }
  u64 d = rho(n);
  factor(d, v);
  factor(n / d, v);
}
vector<u64> factorize64(u64 n) {
  vector<u64> v;
  factor(n, v);
  sort(v.begin(), v.end());
  return v;
}
