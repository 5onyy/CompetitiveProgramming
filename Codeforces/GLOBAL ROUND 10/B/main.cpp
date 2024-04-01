#include <bits/stdc++.h>

using namespace std;
long long a[3000001],b[3000001];
long long n,k;
bool check()
{
    for (long long i=1; i<=n; i++)
        if (a[i]<0)
            return false;
    return true;
}
int main()
{
    freopen("T.INP","r",stdin);
    long long tests;
    cin>>tests;
    while (tests--)
    {
        cin>>n>>k;
        long long tmpmax=-10000000000;
        long long tmpmin=10000000000;
        for (long long i=1; i<=n; i++)
        {
            cin>>a[i];
            tmpmax=max(tmpmax,a[i]);
            tmpmin=min(tmpmin,a[i]);
        }
        if (k&1)
        {
            for (int i=1;i<=n;i++)
                cout<<tmpmax-a[i]<<" ";
            cout<<endl;
        }
        else
        {
            for (int i=1;i<=n;i++)
                a[i]=tmpmax-a[i];
            tmpmax=tmpmax-tmpmin;
            for (int i=1;i<=n;i++)
                cout<<tmpmax-a[i]<<" ";
            cout<<endl;
        }
    }
    return 0;
}
