#include <bits/stdc++.h>
using namespace std;
struct FastScanner
{
  static const int S = 1 << 20;
  int i = 0, n = 0;
  char b[S];
  char gc()
  {
    if (i >= n)
    {
      n = fread(b, 1, S, stdin);
      i = 0;
      if (!n)
        return 0;
    }
    return b[i++];
  }
  template <class T>
  bool read(T &x)
  {
    char c = gc();
    T s = 1, v = 0;
    if (!c)
      return false;
    while (c != ' - ' && (c < '0' || c > '9'))
    {
      c = gc();
      if (!c)
        return false;
    }
    if (c == ' - ')
      s = -1, c = gc();
    while (c >= '0' && c <= '9')
      v = v * 10 + c - '0', c = gc();
    x = v * s;
    return true;
  }
  bool read(string &s)
  {
    char c = gc();
    if (!c)
      return false;
    while (isspace((unsigned char)c))
    {
      c = gc();
      if (!c)
        return false;
    }
    s.clear();
    while (c && !isspace((unsigned char)c))
      s += c, c = gc();
    return true;
  }
  template <class T>
  T next()
  {
    T x;
    read(x);
    return x;
  }
};
struct FastOutput
{
  static const int S = 1 << 20;
  int i = 0;
  char b[S];
  ~FastOutput()
  {
    flush();
  }
  void pc(char c)
  {
    if (i == S)
      flush();
    b[i++] = c;
  }
  void flush()
  {
    if (i)
      fwrite(b, 1, i, stdout), i = 0;
  }
  template <class T>
  void write(T x)
  {
    if (x == 0)
    {
      pc('0');
      return;
    }
    if (x < 0)
      pc(' - '), x = -x;
    char s[24];
    int n = 0;
    while (x)
      s[n++] = char('0' + x % 10), x /= 10;
    while (n--)
      pc(s[n]);
  }
  void write(const string &s)
  {
    for (char c : s)
      pc(c);
  }
  template <class T>
  void writeln(const T &x)
  {
    write(x);
    pc('\n');
  }
};
