#include <bits/stdc++.h>

using namespace std;
int x,n,m;
int main()
{
    //freopen("t.inp","r",stdin);
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int ans=0;
        scanf("%d %d",&n,&m);
        for (int i=0; i<n; i++)
        {
            scanf("%d",&x);
            ans+=x;
        }
        if (m<n)    printf("-1 \n");
        else if (n==2)  printf("-1 \n");
        else if (n==m)
        {
            printf("%d \n",ans*2);
            for (int i=1; i<n; i++)
            {
                printf("%d %d \n",i,i+1);
            }
            printf("%d %d \n",n,1);
        }
    }
    return 0;
}
