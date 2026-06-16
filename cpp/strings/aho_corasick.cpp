#include <bits/stdc++.h>
using namespace std;
struct Aho {
  static const int A = 26;
  struct N {
    int nx[A], link = 0;
    vector<int> out;
    N() {
      fill(nx, nx + A, -1);
    }
  };
  vector<N> t{N()};
  void add(const string &s, int id) {
    int v = 0;
    for (char ch : s) {
      int c = ch - 'a';
      if (t[v].nx[c] == -1) {
        t[v].nx[c] = t.size();
        t.push_back(N());
      }
      v = t[v].nx[c];
    }
    t[v].out.push_back(id);
  }
  void build() {
    queue<int> q;
    for (int c = 0; c < A; c++) {
      int u = t[0].nx[c];
      if (u == -1)
        t[0].nx[c] = 0;
      else
        q.push(u);
    }
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int c = 0; c < A; c++) {
        int u = t[v].nx[c];
        if (u == -1)
          t[v].nx[c] = t[t[v].link].nx[c];
        else
          t[u].link = t[t[v].link].nx[c], q.push(u);
      }
    }
  }
  template <class F> void run(const string &s, F f) {
    int v = 0;
    for (int i = 0; i < (int)s.size(); i++) {
      v = t[v].nx[s[i] - 'a'];
      for (int u = v; u; u = t[u].link) {
        for (int id : t[u].out)
          f(id, i);
      }
      for (int id : t[0].out)
        f(id, i);
    }
  }
};
