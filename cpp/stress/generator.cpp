#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv)
{
  long long seed =
      argc > 1 ? atoll(argv[1]) : chrono::steady_clock::now().time_since_epoch().count();
  mt19937 rng(seed);
  int n = uniform_int_distribution<int>(1, 10)(rng);
  cout << n << '\n';
  for (int i = 0; i < n; i++)
    cout << uniform_int_distribution<int>(-20, 20)(rng) << " \n"[i + 1 == n];
}
