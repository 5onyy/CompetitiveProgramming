#include <bits/stdc++.h>

using namespace std;
int a[10000001];
int main()
{
    freopen("T.INP","r",stdin);
    int tests;
    cin>>tests;
    while (tests--)
    {
        int n;
        cin>>n;
        int lc=0;
        for (int i=0; i<n; i++)
            cin>>a[i];
        while (a[lc]==1 && lc<n)
            lc++;
        if (lc<n)
        {
            if (! (lc&1))
                cout<<"First"<<endl;
            else
                cout<<"Second"<<endl;
        }
        else if (lc==n)
        {
            if (lc&1)
                cout<<"First"<<endl;
            else
                cout<<"Second"<<endl;
        }
    }
    return 0;
}
