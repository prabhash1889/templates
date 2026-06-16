#include <bits/stdc++.h>
using namespace std;
struct SuffixArray {
  string s;
  vector<int> sa, rank, lcp;
  SuffixArray() {}
  SuffixArray(string x) {
    build(x);
  }
  void build(string x) {
    s = x;
    int n = s.size();
    sa.resize(n);
    rank.resize(n);
    iota(sa.begin(), sa.end(), 0);
    for (int i = 0; i < n; i++)
      rank[i] = s[i];
    vector<int> tmp(n);
    for (int k = 1;; k <<= 1) {
      sort(sa.begin(), sa.end(), [&](int a, int b) {
        if (rank[a] != rank[b])
          return rank[a] < rank[b];
        int ra = a + k < n ? rank[a + k] : -1, rb = b + k < n ? rank[b + k] : -1;
        return ra < rb;
      });
      tmp[sa[0]] = 0;
      for (int i = 1; i < n; i++) {
        auto key = [&](int a) { return pair<int, int>{rank[a], a + k < n ? rank[a + k] : -1}; };
        tmp[sa[i]] = tmp[sa[i - 1]] + (key(sa[i - 1]) != key(sa[i]));
      }
      rank = tmp;
      if (rank[sa.back()] == n - 1)
        break;
    }
    lcp.assign(max(0, n - 1), 0);
    for (int i = 0, h = 0; i < n; i++) {
      int r = rank[i];
      if (r == n - 1) {
        h = 0;
        continue;
      }
      int j = sa[r + 1];
      while (i + h < n && j + h < n && s[i + h] == s[j + h])
        h++;
      lcp[r] = h;
      if (h)
        h--;
    }
  }
};
