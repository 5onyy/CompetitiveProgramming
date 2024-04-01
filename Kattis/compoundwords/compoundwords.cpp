#include <bits/stdc++.h>
using namespace std;

int main() {
  string words;
  unordered_set<string> take_in;
  set<string> give_out;
  while (cin >> words)
    take_in.insert(words);
  for (auto &s1 : take_in)
    for (auto &s2 : take_in) {
      if (s1 == s2) continue;
      give_out.insert(s1+s2);
      give_out.insert(s2+s1);
    }
  for (auto &combo : give_out) cout << combo << endl;
  return 0;
}
