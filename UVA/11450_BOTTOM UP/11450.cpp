#include<bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;
bool ans[21][201];
int n,m,c,g;
int price[21][21];
int main()
{
    fastIO;
    freopen("11450.INP","r",stdin);
    freopen("11450.OUT","w",stdout);
    cin>>n;
    while (n--)
    {
        cin>>m>>c;
        for (int g=0;g<c;g++)
        {
            cin>>price[g][0];
            for (int j=1;j<=price[g][0];j++)
            {
                cin>>price[g][j];
            }
        }
        memset(ans,false,sizeof(ans));
        for (int i=1;i<=price[0][0];i++)
            if (m-price[0][i]>=0)
                ans[0][m-price[0][i]]=true;
        for (g=1;g<c;g++)
        {
            for (int j=0;j<m;j++)
            {
                if (ans[g-1][j])
                {
                    for (int i=1;i<=price[g][0];i++)
                    {
                        if (j-price[g][i]>=0)
                            ans[g][j-price[g][i]]=true;
                    }
                }
            }
        }
        int moc=0;
        while (moc<=m && !ans[c-1][moc])
            ++moc;
        if (moc==m+1)   cout<<"no solution"<<endl;
        else cout<<m-moc<<endl;
    }
    return 0;
}
