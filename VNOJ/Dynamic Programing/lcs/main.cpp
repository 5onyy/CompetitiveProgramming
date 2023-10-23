#include <bits/stdc++.h>

using namespace std;
int n,m;
int dp[1001][1001],a[1001],b[1001];
int main()
{
    freopen("T.INP","r",stdin);
    cin>>n>>m;
    for (int i=1;i<=n;i++)  cin>>a[i];
    for (int j=1;j<=m;j++)  cin>>b[j];
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            dp[i][j]= a[i]==b[j] ? dp[i-1][j-1]+1 : max(dp[i][j-1],dp[i-1][j]);
        }
    }
    cout<<dp[n][m];
    return 0;
}
