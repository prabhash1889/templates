#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll exgcd(ll a, ll b, ll &x, ll &y)
{
  if (!b)
  {
    x = 1;
    y = 0;
    return a;
  }
  ll x1, y1, g = exgcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return g;
}
optional<ll> inv_mod(ll a, ll m)
{
  ll x, y, g = exgcd(a, m, x, y);
  if (g != 1)
    return nullopt;
  x %= m;
  if (x < 0)
    x += m;
  return x;
}
optional<pair<ll, ll>> crt_pair(ll r1, ll m1, ll r2, ll m2)
{
  ll x, y, g = exgcd(m1, m2, x, y);
  if ((r2 - r1) % g)
    return nullopt;
  __int128 t = (__int128)(r2 - r1) / g * x;
  ll mod = m2 / g, k = (ll)(t % mod);
  if (k < 0)
    k += mod;
  ll lcm = m1 / g * m2;
  ll ans = (r1 + (__int128)m1 * k) % lcm;
  if (ans < 0)
    ans += lcm;
  return pair<ll, ll>{ans, lcm};
}
