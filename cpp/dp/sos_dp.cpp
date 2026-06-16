#include <bits/stdc++.h>
using namespace std;
template <class T> vector<T> sos_subsets(vector<T> f, int n) {
  for (int b = 0; b < n; b++)
    for (int m = 0; m < (1 << n); m++)
      if (m >> b & 1)
        f[m] += f[m ^ (1 << b)];
  return f;
}
template <class T> vector<T> sos_supersets(vector<T> f, int n) {
  for (int b = 0; b < n; b++)
    for (int m = 0; m < (1 << n); m++)
      if (!(m >> b & 1))
        f[m] += f[m | (1 << b)];
  return f;
}
template <class T> vector<T> mobius_subsets(vector<T> f, int n) {
  for (int b = 0; b < n; b++)
    for (int m = 0; m < (1 << n); m++)
      if (m >> b & 1)
        f[m] -= f[m ^ (1 << b)];
  return f;
}
