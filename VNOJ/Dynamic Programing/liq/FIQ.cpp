#include <bits/stdc++.h>

using namespace std;
int a[1001],l[1001];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1; i<=n; i++)
        {   scanf("%d",&a[i]);
            l[i]=1;
        }
    l[0]=0;
    l[1]=1;
    int ans=1;
    for (int i=2; i<=n; i++)
    {
        for (int j=1; j<i; j++)
        {
             if (a[i]>a[j])
                l[i]=max(l[i],l[j]+1);
        }
        ans=max(ans,l[i]);
    }
    printf("%d",ans);
    return 0;
}
