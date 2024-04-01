#include <bits/stdc++.h>
using namespace std;
using ll = long long;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
const string NAME = "template";
const int NTEST = 100;
ll Rand(ll l, ll h)
{
      assert(l <= h);
      ll res = 0;
      for (int i = 0; i < 4; i++)
            res = (res << 15) ^ (rd() & ((1 << 15) - 1));
      return l + res % (h - l + 1);
}
int main()
{
      srand(time(NULL));
      for (int iTest = 1; iTest <= NTEST; iTest++)
      {
            ofstream inp((NAME + ".inp").c_str());
            // gen code ( inp << . . . << . . . )
            inp.close();
            system((NAME + ".exe").c_str());      // (”./” + NAME)
            system((NAME + "_trau.exe").c_str()); // (”./” + NAME + ”trau” 
            if (system(("fc " + NAME + ".out " + NAME + ".ans").c_str()))
            { // fc −> d i f f
                  cout << "Test " << iTest << ": WRONG!\n";
                  return 0;
            }
            cout << "Test " << iTest << ": CORRECT!\n";
      }
      return 0;
}
