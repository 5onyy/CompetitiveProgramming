#include <bits/stdc++.h>
#define  inf 999999
using namespace std;
int m,n,ans=-inf;
int dp[151][151],a[151][151];
void solve()
{
    for (int i=1;i<=n;i++) dp[0][i] = dp[n+1][i] = -inf;
    for (int j=1;j<=n;j++)
    {
        for (int i=1;i<=m;i++)
        {
            dp[i][j]=max(dp[i-1][j-1],max(dp[i][j-1],dp[i+1][j-1]))+a[i][j];
        }
    }
    for (int j=1;j<=m;j++)
        ans=max(ans,dp[j][n]);
}
int main()
{
    cin>>m>>n;
    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=n;j++)
                cin>>a[i][j];
    }
    solve();
//    for (int i=1;i<=m;i++)
//        {
//            for (int j=1;j<=n;j++)
//                cout<<dp[i][j]<<" ";
//            cout<<endl;
//        }
    cout<<ans;
    return 0;
}
