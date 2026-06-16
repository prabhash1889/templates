#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-12L;
struct P {
  long double x, y;
  P operator+(P o) const {
    return {x + o.x, y + o.y};
  }
  P operator-(P o) const {
    return {x - o.x, y - o.y};
  }
  P operator*(long double k) const {
    return {x * k, y * k};
  }
};
long double dot(P a, P b) {
  return a.x * b.x + a.y * b.y;
}
long double cross(P a, P b) {
  return a.x * b.y - a.y * b.x;
}
int sgn(long double x) {
  return (x > EPS) - (x < -EPS);
}
bool on_seg(P a, P b, P p) {
  return !sgn(cross(b - a, p - a)) && sgn(dot(p - a, p - b)) <= 0;
}
bool seg_inter(P a, P b, P c, P d) {
  long double c1 = cross(b - a, c - a), c2 = cross(b - a, d - a), c3 = cross(d - c, a - c),
              c4 = cross(d - c, b - c);
  if (sgn(c1) * sgn(c2) < 0 && sgn(c3) * sgn(c4) < 0)
    return 1;
  return on_seg(a, b, c) || on_seg(a, b, d) || on_seg(c, d, a) || on_seg(c, d, b);
}
optional<P> line_inter(P a, P b, P c, P d) {
  long double den = cross(b - a, d - c);
  if (fabsl(den) < EPS)
    return nullopt;
  return a + (b - a) * (cross(c - a, d - c) / den);
}
