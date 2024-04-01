#include <bits/stdc++.h>

using namespace std;
int d[10000],a[10000];
int main()
{
    //freopen("T.INP","r",stdin);
    int tests;
    cin>>tests;
    while (tests--)
    {
        int kq=0;
        memset(d,0,sizeof d);
        memset(a,0,sizeof a);
        int n;
        cin>>n;
        for (int i=0; i<n; i++)
            cin>>a[i];
        for (int i=2;i<2*n+1;i++)
        {
            memset(d,0,sizeof d);
            int ans=0;
            for (int j=0;j<n;j++)
            {
                if (d[j] || a[j]>=i)    continue;
                for (int k=n-1;k>=0;k--)
                {
                    if (!d[k] && a[j]+a[k]==i && j!=k)
                    {
                        d[j]=d[k]=1;
                        ans++;
                        break;
                    }
                }
            }
            kq=max(kq,ans);
        }
        cout<<kq<<endl;
    }
    return 0;
}
