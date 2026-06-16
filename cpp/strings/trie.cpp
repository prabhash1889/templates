#include <bits/stdc++.h>
using namespace std;
struct Trie {
  struct N {
    int nx[26];
    int pass = 0, end = 0;
    N() {
      fill(nx, nx + 26, -1);
    }
  };
  vector<N> tr{N()};
  void insert(const string &s) {
    int u = 0;
    tr[u].pass++;
    for (char ch : s) {
      int c = ch - 'a';
      if (tr[u].nx[c] == -1) {
        tr[u].nx[c] = tr.size();
        tr.push_back(N());
      }
      u = tr[u].nx[c];
      tr[u].pass++;
    }
    tr[u].end++;
  }
  bool contains(const string &s) {
    int u = 0;
    for (char ch : s) {
      int c = ch - 'a';
      if (tr[u].nx[c] == -1)
        return 0;
      u = tr[u].nx[c];
    }
    return tr[u].end;
  }
};
