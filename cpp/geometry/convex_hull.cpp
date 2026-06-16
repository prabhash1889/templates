#include <bits/stdc++.h>
using namespace std;
template <class T> struct P {
  T x, y;
  bool operator<(P o) const {
    return x == o.x ? y < o.y : x < o.x;
  }
  bool operator==(P o) const {
    return x == o.x && y == o.y;
  }
};
template <class T> T cross(P<T> a, P<T> b, P<T> c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
template <class T> vector<P<T>> convex_hull(vector<P<T>> p, bool col = 0) {
  sort(p.begin(), p.end());
  p.erase(unique(p.begin(), p.end()), p.end());
  vector<P<T>> h;
  auto bad = [&](P<T> a, P<T> b, P<T> c) {
    T cr = cross(a, b, c);
    return col ? cr < 0 : cr <= 0;
  };
  for (auto x : p) {
    while (h.size() >= 2 && bad(h[h.size() - 2], h.back(), x))
      h.pop_back();
    h.push_back(x);
  }
  int lo = h.size();
  for (int i = (int)p.size() - 2; i >= 0; i--) {
    while ((int)h.size() > lo && bad(h[h.size() - 2], h.back(), p[i]))
      h.pop_back();
    h.push_back(p[i]);
  }
  if (!h.empty())
    h.pop_back();
  return h;
}
