#include <bits/stdc++.h>
using namespace std;
template <class T> struct Matrix {
  int n, m;
  vector<vector<T>> a;
  Matrix(int n = 0, int m = 0, T v = T{}) : n(n), m(m), a(n, vector<T>(m, v)) {}
  static Matrix I(int n) {
    Matrix r(n, n);
    for (int i = 0; i < n; i++)
      r.a[i][i] = 1;
    return r;
  }
  vector<T> &operator[](int i) {
    return a[i];
  }
  Matrix operator*(const Matrix &o) const {
    Matrix r(n, o.m, T{});
    for (int i = 0; i < n; i++)
      for (int k = 0; k < m; k++)
        for (int j = 0; j < o.m; j++)
          r[i][j] += a[i][k] * o.a[k][j];
    return r;
  }
};
template <class T> Matrix<T> mpow(Matrix<T> a, long long e) {
  auto r = Matrix<T>::I(a.n);
  while (e) {
    if (e & 1)
      r = r * a;
    a = a * a;
    e >>= 1;
  }
  return r;
}
