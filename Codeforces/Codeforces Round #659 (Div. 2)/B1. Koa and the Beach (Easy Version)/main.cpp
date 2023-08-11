#include <bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    cin>>test;
    while (test--)
    {
        int d[1001],p[1001],d1[1001];
        scanf("%d %d %d",&n,&k,&l);
        for (int i=1;i<=n;i++)
            scanf("%d",&d[i]);
        for (int i=1;i<=k;i++)
            p[i]=p[2*k-i]=i;
        int x=0,t=0;
        while (x<n+1)
        {
            if (d[x]>l)
            {
                for (int i=1;i<=n;i++)
                {
                    d1[i]=d[i]+p[t % (2*k)];
                }
            }
        }
    }
    return 0;
}
