#include <bits/stdc++.h>

using namespace std;
int n,dp[70001],l[70001],r[70001];
void solve()
{
    dp[1]=l[1];    dp[0]=0;
    for (int i=2;i<=n;i++)
        dp[i]=min(dp[i-1]+l[i],dp[i-2]+r[i]);
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&l[i]);
    for (int i=2;i<=n;i++)
        scanf("%d",&r[i]);
    solve();
    printf("%d",dp[n]);
    return 0;
}
