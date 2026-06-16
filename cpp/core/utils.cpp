#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T> bool chmin(T &a, T b) {
  return b < a ? (a = b, 1) : 0;
}
template <class T> bool chmax(T &a, T b) {
  return a < b ? (a = b, 1) : 0;
}
template <class T> T ceil_div(T a, T b) {
  assert(b);
  if (b < 0)
    a = -a, b = -b;
  return a >= 0 ? (a + b - 1) / b : -((-a) / b);
}
template <class T> T floor_div(T a, T b) {
  assert(b);
  if (b < 0)
    a = -a, b = -b;
  return a >= 0 ? a / b : -((-a + b - 1) / b);
}
template <class T> vector<T> compress_vals(vector<T> v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  return v;
}
template <class T> int id(const vector<T> &v, T x) {
  return lower_bound(v.begin(), v.end(), x) - v.begin();
}
template <class F> struct y_combinator {
  F f;
  template <class... A> decltype(auto) operator()(A &&...a) {
    return f(*this, forward<A>(a)...);
  }
};
