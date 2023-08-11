#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("T.INP","r",stdin);
    int tests;
    cin>>tests;
    while (tests--)
    {
        int n,x=0,ans=0;
        cin>>n;
        ans+=1<<n;
        for (int i=1;i<n;i++)
            x|= (1<<i);
        for (int i=1;i<=n/2-1;i++)
        {
            ans+=(1<<i);
            x&=~(1<<i);
        }
        cout<<ans-x<<endl;
    }
    return 0;
}
