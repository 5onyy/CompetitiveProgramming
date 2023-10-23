#include <bits/stdc++.h>

using namespace std;
int n,m;
int a[500],b[500];
void solve()
{
    for (int ans=0;ans<=(1<<9);ans++)
    {
        int lc=0;
        for (int i=1;i<=n;i++)
        {
            bool bad=true;
            for (int j=1;j<=m;j++)
            {
                int tmp=a[i]&b[j];
                if ( (tmp|ans) <= ans)
                {
                    bad=false;  break;
                }
            }
            if (bad==false) lc++;
        }
        if (lc==n)
        {
            cout<<ans;
            break;
        }
    }
}
int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)  cin>>a[i];
    for (int j=1;j<=m;j++)  cin>>b[j];
    solve();
    return 0;
}
