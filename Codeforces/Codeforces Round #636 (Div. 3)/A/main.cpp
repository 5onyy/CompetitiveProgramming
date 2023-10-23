#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("T.INP","r",stdin);
    int tests;
    cin>>tests;
    while (tests--)
    {
        int n;
        cin>>n;
        int lc=3;
        while (n % lc !=0)
        {
            lc <<= 1;
            lc |= 1;
        }
        cout<<n/lc<<endl;
    }
    return 0;
}
