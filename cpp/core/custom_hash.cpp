#include <bits/stdc++.h>
using namespace std;
struct custom_hash
{
  static uint64_t splitmix64(uint64_t x)
  {
    x += 0x9e3779b97f4a7c15ULL;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const
  {
    static const uint64_t R = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + R);
  }
  template <class A, class B>
  size_t operator()(pair<A, B> p) const
  {
    return (*this)(((uint64_t)p.first << 32) ^ (uint64_t)p.second);
  }
};
template <class K, class V>
using safe_hash_map = unordered_map<K, V, custom_hash>;
template <class K>
using safe_hash_set = unordered_set<K, custom_hash>;
