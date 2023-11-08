#include <bits/stdc++.h>

using namespace std;
int f[100],s,n,a[100];
int main()
{
    freopen("T.INP","r",stdin);
    scanf("%d %d",&n,&s);
    for (int i=1;i<=n;i+=1)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for (int i=1;i<=s;i++)
        f[i]=(int)1e9;
    f[1]=1;
    f[0]=0;
    for (int t=2;t<=s;t++)
    {
        for (int i=1;i<=n;i++)
        {
            if (t>=a[i])
                f[t]=min(f[t],f[t-a[i]]+1);
        }
    }
    printf("%d",f[s]);
    return 0;
}
