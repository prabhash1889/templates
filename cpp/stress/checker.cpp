#include <bits/stdc++.h>
using namespace std;
int main() {
  for (int tc = 1;; tc++) {
    string s = to_string(tc);
    system((". / gen " + s + "> input.txt").c_str());
    system(". / sol <input.txt> out1.txt");
    system(". / brute <input.txt> out2.txt");
    if (system("diff - w out1.txt out2.txt")) {
      cerr << "WA seed " << tc << "\n";
      system("cat input.txt");
      break;
    }
    if (tc % 100 == 0)
      cerr << "OK " << tc << "\n";
  }
}
