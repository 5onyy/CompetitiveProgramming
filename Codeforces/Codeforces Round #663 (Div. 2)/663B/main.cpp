#include <bits/stdc++.h>

using namespace std;
char a[105][105];
int n,m;
int check[105][105];
int main()
{
    //freopen("T.INP","r",stdin);
    int tests;
    cin>>tests;
    while (tests--)
    {
        memset(check,0,sizeof check);
        int ans=0;
        cin>>n>>m;
        for (int i=1; i<=n; i++)
             for (int j=1; j<=m; j++)
                cin>>a[i][j];
        for (int j=m-1; j>=1; j--)
        {
            if (a[n][j]=='D')
            {
                ans++;
                a[n][j]='R';
                check[n][j]=true;
            }
        }
        for (int j=1;j<=m;j++)
            check[n][j]=true;
        for (int i=n-1;i>=1;i--)
        {
            for (int j=m;j>=1;j--)
            {
                if (a[i][j]=='R' && !check[i][j+1])
                {
                    a[i][j]='D';
                    check[i][j]=true;
                    ans++;
                }
                else if (a[i][j]=='D' && !check[i+1][j])
                {
                    a[i][j]='R';
                    check[i][j]=true;
                    ans++;
                }
                else check[i][j]=true;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
