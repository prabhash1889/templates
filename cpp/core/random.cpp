#include <bits/stdc++.h>
using namespace std;
struct Random {
  mt19937 rng;
  mt19937_64 rng64;
  Random(uint64_t seed = chrono::steady_clock::now().time_since_epoch().count())
      : rng(seed), rng64(seed) {}
  int randint(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
  }
  long long randll(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rng64);
  }
  template <class T> void shuffle_vec(vector<T> &a) {
    shuffle(a.begin(), a.end(), rng);
  }
  vector<int> perm(int n, int base = 0) {
    vector<int> p(n);
    iota(p.begin(), p.end(), base);
    shuffle_vec(p);
    return p;
  }
  vector<pair<int, int>> tree(int n) {
    vector<pair<int, int>> e;
    for (int i = 2; i <= n; i++)
      e.push_back({i, randint(1, i - 1)});
    shuffle_vec(e);
    return e;
  }
} rnd;
