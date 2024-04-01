#include <bits/stdc++.h>
using namespace std;
int a[maxN][maxN];
int n,m,sx,sy;
void solve()
{
    for (int dem=1;dem<=n*m;dem++)
    {
        int tmp=0;
        a[sx][sy]=1;
        cout<<sx<<" "<<sy<<endl;
        for (int i=1;i<=m;i++)
        {
            if (a[sx][i]==0)
            {
                sy=i;   tmp=1;
                break;
            }
            if (!tmp)
            {
                for (int i=1;i<=n;i++)
                {
                    if (a[i][sy]==0)
                    {
                        sx=i;   tmp=1;
                        break;
                    }
                }
            }
        }
    }
}
int main()
{
    cin>>n>>m>>sx>>sy;
    solve();
//    cout<<sx<<" "<<sy<<endl;
    return 0;
}
