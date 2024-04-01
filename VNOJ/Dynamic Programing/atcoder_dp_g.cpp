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
#define hardio(x)      freopen(x".inp","r",stdin), freopen(x".out","w",stdout);
#define rall(x)        x.rbegin(),x.rend()

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int maxN=1001;
const int BASE=311;
const int N=1e5+5;
const int MOD=1000000003;
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

int n,m,ans=0;
vector<vi> a;
int deg[N];
vi visit,dp;

void dfs(int u)
{
    if (dp[u])  return;
    if (sz(a[u])==0)
        {dp[u]=0;   return;}
    for (int v:a[u])
    {
        dfs(v);
        dp[u]=max(dp[v]+1,dp[u]);
        ans=max(ans,dp[u]);
    }
}

signed main()
{
    fastIO;
    cin>>n>>m;
    a.assign(n+1,vi());
    for (int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        a[u].pb(v);
        deg[v]++;
    }
    for (int i=1;i<=n;i++)
    {
        if (!deg[i])
            {dp.assign(n+1,0);     dfs(i);}
    }
    cout<<ans;
}
