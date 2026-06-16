#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T> struct ordered_multiset {
  using P = pair<T, int>;
  tree<P, null_type, less<P>, rb_tree_tag, tree_order_statistics_node_update> tr;
  int timer = 0;
  void insert(T x) {
    tr.insert({x, timer++});
  }
  bool erase_one(T x) {
    auto it = tr.lower_bound({x, -1});
    if (it == tr.end() || it->first != x)
      return 0;
    tr.erase(it);
    return 1;
  }
  int order_of_key(T x) {
    return tr.order_of_key({x, -1});
  }
  T kth(int k) {
    return tr.find_by_order(k)->first;
  }
};
