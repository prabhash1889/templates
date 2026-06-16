#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll solve_fast(vector<int> a) {
  return accumulate(a.begin(), a.end(), 0LL);
}
ll solve_brute(vector<int> a) {
  ll ans = 0;
  for (int x : a)
    ans += x;
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  if (!(cin >> n))
    return 0;
  vector<int> a(n);
  for (int &i : a)
    cin >> i;
  cout << solve_brute(a) << '\n';
}
