#include <bits/stdc++.h>

using namespace std;
long long a[1000001];
int main()
{
    freopen("T.INP","r",stdin);
    long long tests;
    cin>>tests;
    while (tests--)
    {
        long long ans=0;
        long long n;
        cin>>n;
        for (long long i=0;i<n;i++)
            cin>>a[i];
        long long lc=a[0];
        for (long long i=1;i<n;i++)
        {
            if (a[i]>0 && lc>0)
                lc=max(lc,a[i]);
            else if (a[i]<0 && lc<0)
                lc=max(lc,a[i]);
            else
            {
                ans+=lc;
                lc=a[i];
            }
        }
        cout<<ans+lc<<endl;
    }
    return 0;
}
