#include <bits/stdc++.h>
using namespace std;
namespace dbg_detail
{
  template <class A, class B>
  ostream &print(ostream &os, const pair<A, B> &p)
  {
    return os << '(' << p.first << ", " << p.second << ')';
  }
  template <class T, class = void>
  struct iterable : false_type
  {
  };
  template <class T>
  struct iterable<T, void_t<decltype(begin(declval<T>())), decltype(end(declval<T>()))>> : true_type
  {
  };
  template <class T>
  enable_if_t<!iterable<T>::value || is_same_v<T, string>, ostream &> print(ostream &os, const T &x)
  {
    return os << x;
  }
  template <class T>
  enable_if_t<iterable<T>::value && !is_same_v<T, string>, ostream &> print(ostream &os, const T &v)
  {
    os << '{';
    bool f = 1;
    for (auto &&x : v)
    {
      if (!f)
        os << ", ";
      f = 0;
      print(os, x);
    }
    return os << '}';
  }
  inline void out()
  {
    cerr << '\n';
  }
  template <class H, class... T>
  void out(H &&h, T &&...t)
  {
    print(cerr, forward<H>(h));
    if (sizeof...(t))
      cerr << " | ";
    out(forward<T>(t)...);
  }
} // namespace dbg_detail
#ifdef LOCAL
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "] = ", dbg_detail::out(__VA_ARGS__)
#else
#define dbg(...) ((void)0)
#endif
