#include <bits/stdc++.h>
using namespace std;
const long double EPSC = 1e-12L;
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
long double norm(P p) {
  return hypotl(p.x, p.y);
}
P rot90(P p) {
  return {-p.y, p.x};
}
vector<P> circle_circle(P a, long double r, P b, long double R) {
  P d = b - a;
  long double D = norm(d);
  if (D < EPSC || D > r + R + EPSC || D + min(r, R) + EPSC < max(r, R))
    return {};
  long double x = (D * D + r * r - R * R) / (2 * D), h2 = r * r - x * x;
  P base = a + d * (x / D);
  if (fabsl(h2) <= EPSC)
    return {base};
  P off = rot90(d) * (sqrtl(max((long double)0, h2)) / D);
  return {base - off, base + off};
}
