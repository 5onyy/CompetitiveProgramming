#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("T.INP","r",stdin);
    int tests;
    cin>>tests;
    while (tests--)
    {
        int x,y,n,ans=0;
        cin>>x>>y>>n;
        int DIV=n/x;
        int MOD=n%x;
        if (MOD==y) ans=n;
        else if (MOD<y)
        {
            DIV--;
            ans=DIV*x+y;
        }
        else
            ans=n-(MOD-y);
        cout<<ans<<endl;
    }
    return 0;
}
