#include <bits/stdc++.h>
using namespace std;
template <class T>
struct Point
{
  T x, y;
  Point(T x = 0, T y = 0) : x(x), y(y) {}
  Point operator+(Point o) const
  {
    return {x + o.x, y + o.y};
  }
  Point operator-(Point o) const
  {
    return {x - o.x, y - o.y};
  }
  Point operator*(T k) const
  {
    return {x * k, y * k};
  }
  bool operator<(Point o) const
  {
    return x == o.x ? y < o.y : x < o.x;
  }
};
template <class T>
T dot(Point<T> a, Point<T> b)
{
  return a.x * b.x + a.y * b.y;
}
template <class T>
T cross(Point<T> a, Point<T> b)
{
  return a.x * b.y - a.y * b.x;
}
template <class T>
T cross(Point<T> a, Point<T> b, Point<T> c)
{
  return cross(b - a, c - a);
}
template <class T>
long double dist(Point<T> a, Point<T> b)
{
  auto d = a - b;
  return sqrt((long double)dot(d, d));
}
