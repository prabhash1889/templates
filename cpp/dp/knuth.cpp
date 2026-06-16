#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll KINF = (1LL << 62);
template <class Cost>
vector<vector<ll>> knuth(int n, Cost cost)
{
  vector dp(n, vector<ll>(n));
  vector opt(n, vector<int>(n));
  for (int i = 0; i < n; i++)
    opt[i][i] = i;
  for (int len = 2; len <= n; len++)
    for (int l = 0; l + len <= n; l++)
    {
      int r = l + len - 1;
      dp[l][r] = KINF;
      for (int k = opt[l][r - 1]; k <= opt[l + 1][r]; k++)
      {
        ll v = (k > l ? dp[l][k - 1] : 0) + (k < r ? dp[k + 1][r] : 0) + cost(l, r);
        if (v < dp[l][r])
          dp[l][r] = v, opt[l][r] = k;
      }
    }
  return dp;
}
