#include <bits/stdc++.h>

using namespace std;
int col[1005][1005],row[1005][1005],f[1005][1005],a[1005][1005];
int main()
{
    memset(a,-1,sizeof a);
    int n,m;
    scanf("%d %d",&n,&m);
//    for (int i=0;i<n;i++)
//        {
//            for (int j=0;j<m;j++)
//            cout<<a[i][j]<<" ";
//            cout<<endl;
//        }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    int ans=INT_MIN;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            col[i][j]= a[i][j]==a[i-1][j] ? col[i-1][j]+1 : 1;
            row[i][j]= a[i][j]==a[i][j-1] ? row[i][j-1]+1 : 1;
            f[i][j]= a[i][j]==a[i-1][j-1] ? min(col[i][j],min(row[i][j],f[i-1][j-1]+1)) : 1;
            ans=max(ans,f[i][j]);
        }
    }
    cout<<ans;
    return 0;
}