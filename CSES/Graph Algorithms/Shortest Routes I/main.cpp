#include<bits/stdc++.h>

using namespace std;

#define fastIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mp make_pair
#define inf LLONG_MAX
#define sz(x) (int)(x).size()
#define log2i(x) (64 - __builtin_clzll(1ll * (x)) - 1)
#define hardio(x)      freopen(x".inp","r",stdin), freopen(x".out","w",stdout);
#define all(x)         x.begin(),x.end()
#define rall(x)        x.rbegin(),x.rend()

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;


const int maxN=1001;
const int BASE=311;
const int N=1e5+5;
const int MOD=1000000003;
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

ll d[N];
int vis[N];
int n,m;
vector<vii> a;

void dijkstra(int s)
{
    for (int i=1;i<=n;i++)
        d[i]=inf;
    priority_queue<pll, vector<pll>, greater<pll> > pq;
    pq.push(pll(0,s));
    d[s]=0;
    while (!pq.empty())
    {
        int u=pq.top().se;
        pq.pop();
        if (vis[u])   continue;
        vis[u]=1;
        for (int i=0;i<sz(a[u]);i++)
        {
            int v=a[u][i].fi;
            int w=a[u][i].se;
            if (d[v]>d[u]+w)
            {
                pq.push(pll(d[u]+w,v));
                d[v]=d[u]+w;
            }
        }
    }
}

signed main()
{
    //hardio("t");
    fastIO;
    cin>>n>>m;
    a.assign(n+1,vii());
    for (int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        a[u].pb(ii(v,w));
    }
    dijkstra(1);
    for (int i=1;i<=n;i++)
        cout<<d[i]<<" ";
}
