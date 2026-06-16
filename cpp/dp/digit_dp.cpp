#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct DigitDP
{
  string s;
  int mod;
  vector<vector<array<ll, 2>>> memo;
  ll dfs(int pos, int rem, bool tight, bool started)
  {
    if (pos == (int)s.size())
      return started && rem == 0;
    if (!tight && memo[pos][rem][started] != -1)
      return memo[pos][rem][started];
    int lim = tight ? s[pos] - '0' : 9;
    ll ans = 0;
    for (int d = 0; d <= lim; d++)
    {
      bool ns = started || d;
      ans += dfs(pos + 1, ns ? (rem + d) % mod : 0, tight && d == lim, ns);
    }
    if (!tight)
      memo[pos][rem][started] = ans;
    return ans;
  }
  ll solve(long long N, int m)
  {
    if (N < 0)
      return 0;
    s = to_string(N);
    mod = m;
    memo.assign(s.size(), vector<array<ll, 2>>(mod, {-1, -1}));
    return dfs(0, 0, 1, 0);
  }
};
