#include <bits/stdc++.h>
using namespace std;
template <int MOD>
struct ModInt
{
  int v;
  ModInt(long long x = 0)
  {
    v = x % MOD;
    if (v < 0)
      v += MOD;
  }
  static int mod()
  {
    return MOD;
  }
  ModInt &operator+=(ModInt o)
  {
    v += o.v;
    if (v >= MOD)
      v -= MOD;
    return *this;
  }
  ModInt &operator-=(ModInt o)
  {
    v -= o.v;
    if (v < 0)
      v += MOD;
    return *this;
  }
  ModInt &operator*=(ModInt o)
  {
    v = (long long)v * o.v % MOD;
    return *this;
  }
  friend ModInt power(ModInt a, long long e)
  {
    ModInt r = 1;
    while (e)
    {
      if (e & 1)
        r *= a;
      a *= a;
      e >>= 1;
    }
    return r;
  }
  friend ModInt inv(ModInt a)
  {
    return power(a, MOD - 2);
  }
  ModInt &operator/=(ModInt o)
  {
    return *this *= inv(o);
  }
  friend ModInt operator+(ModInt a, ModInt b)
  {
    return a += b;
  }
  friend ModInt operator-(ModInt a, ModInt b)
  {
    return a -= b;
  }
  friend ModInt operator*(ModInt a, ModInt b)
  {
    return a *= b;
  }
  friend ModInt operator/(ModInt a, ModInt b)
  {
    return a /= b;
  }
  friend ostream &operator<<(ostream &os, ModInt x)
  {
    return os << x.v;
  }
};
using mint = ModInt<1000000007>;
using mint998 = ModInt<998244353>;
