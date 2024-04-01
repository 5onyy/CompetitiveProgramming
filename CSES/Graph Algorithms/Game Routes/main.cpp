#include<bits/stdc++.h>

using namespace std;

#define fastIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mp make_pair
#define inf 999999999
#define sz(x) (int)(x).size()
#define int long long
#define double long double
#define log2(x)        log(x)/log(2.0)


typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int maxN=1001;
const int BASE=311;
const int MOD= 1e9+7;
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

int n,m;
int dp[1000000];
vector<vi> a;
vi topo,visit;

void dfs(int u)
{
    visit[u]=1;
    for (int v:a[u])
        if (!visit[v])
            dfs(v);
    topo.pb(u);
}

signed main()
{
//    freopen(".INP","r",stdin);
//    freopen(".OUT","w",stdout);
    cin>>n>>m;
    a.resize(n+1,vi());
    visit.assign(n+1,0);
    for (int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        a[u].pb(v);
    }
    dfs(1);
    dp[1]=1;
    for (int i=sz(topo)-1;i>=0;i--)
    {
        int u=topo[i];
        for (int v:a[u])
            dp[v]=(dp[v]+dp[u])%MOD;
    }
    cout<<dp[n];
}
