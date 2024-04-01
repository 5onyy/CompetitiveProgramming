#include<bits/stdc++.h>

using namespace std;

#define fastIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mp make_pair
#define inf 1e13
#define sz(x) (int)(x).size()
#define log2i(x) (64 - __builtin_clzll(1ll * (x)) - 1)
#define hardio(x)      freopen(x".inp","r",stdin), freopen(x".out","w",stdout);
#define all(x)         x.begin(),x.end()
#define rall(x)        x.rbegin(),x.rend()

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;

const int maxN=1001;
const int BASE=311;
const int N=1e5+5;
const int MOD=1000000003;
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

int n,m,q;
ll a[501][501];

void floyd()
{
    for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
}
signed main()
{
    //hardio("t");
    fastIO;
    cin>>n>>m>>q;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (i!=j)
                a[i][j]=inf;
    for (int i=1;i<=m;i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        a[u][v]=a[v][u]=min(a[u][v],w);
    }
    floyd();
    while (q--)
    {
        int u,v;
        cin>>u>>v;
        if (a[u][v]!=inf)
            cout<<a[u][v]<<endl;
        else cout<<-1<<endl;
    }
}
