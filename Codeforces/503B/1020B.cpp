#include <bits/stdc++.h>

using namespace std;
int n,ans,visit[1001],a[1001][1001];
void dfs(int u)
{
    visit[u]++;
    if (visit[u]==2)
        ans=u;
    for (int v=1;v<=n;v++)
    {
        if (a[u][v] && visit[u]!=2)
            dfs(v);
    }
}
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        a[i][x]=1;
    }
    for (int i=1;i<=n;i++)
    {
        memset(visit,0,sizeof visit);
        dfs(i);
        cout<<ans<<" ";
    }
    return 0;
}
