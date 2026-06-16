#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll DCDP_INF = (1LL << 62);
template <class Cost>
void compute(int l, int r, int optL, int optR, const vector<ll> &prev, vector<ll> &cur, Cost cost) {
  if (l > r)
    return;
  int mid = (l + r) / 2;
  pair<ll, int> best = {DCDP_INF, -1};
  for (int k = optL; k <= min(optR, mid); k++)
    best = min(best, {prev[k] + cost(k, mid), k});
  cur[mid] = best.first;
  compute(l, mid - 1, optL, best.second, prev, cur, cost);
  compute(mid + 1, r, best.second, optR, prev, cur, cost);
}
