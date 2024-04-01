#include<bits/stdc++.h>

using namespace std;

#define fastIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mp make_pair
#define inf INT_MAX
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
typedef vector<pll> vll;

const ll BASE=311;
const ll MOD=1000000003;
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

ll n,m;
vector<vll> a;
vll d;

void dijkstra(int s)
{
    d.assign(n+1,pll(inf,0));
    priority_queue<pll, vector<pll>, greater<pll> > q;
    q.push(pll(0,s));
    d[s]=pll(0,1);
    while (!q.empty())
    {
        ll u=q.top().se;
        q.pop();
        for (int i=0;i<sz(a[u]);i++)
        {
            ll v=a[u][i].fi;
            ll w=a[u][i].se;
            if (d[v].fi>d[u].fi+w)
            {
                d[v]=pll(d[u].fi+w,d[u].se);
                q.push(pll(d[u].fi+w,v));
            }
            else if (d[v].fi==d[u].fi+w)
                d[v].se+=d[u].se;

        }
    }
}

int main()
{
    freopen("QBSCHOOL.INP","r",stdin);
    freopen("QBSCHOOL.OUT","w",stdout);
    cin>>n>>m;
    a.resize(n+1);
    for (int i=0;i<m;i++)
    {
        ll k,u,v,l;
        cin>>k>>u>>v>>l;
        a[u].pb(pll(v,l));
        if (k==2) a[v].pb(pll(u,l));
    }
    dijkstra(1);
    cout<<d[n].fi<<" "<<d[n].se<<endl;
    return 0;
}
//#include<stdio.h>
//#include<vector>
//#include<queue>
//#define MAX   5555
//const int INF=1e9;
//using namespace std;
//typedef long long ll;
//typedef pair<int,int> ii;
//typedef vector<ii> vii;
//int m,n;
//vii g[MAX];
//ll c[MAX];
//int d[MAX];
//int s,e;
//void loadgraph(void) {
//    scanf("%d",&n);
//    scanf("%d",&m);
//    int i,k,u,v,w;
//    for (i=1;i<=m;i=i+1) {
//        scanf("%d",&k);
//        scanf("%d",&u);
//        scanf("%d",&v);
//        scanf("%d",&w);
//        g[u].push_back(ii(v,w));
//        if (k==2) g[v].push_back(ii(u,w));
//    }
//    for (i=1;i<=n;i=i+1) {
//        d[i]=INF;
//        c[i]=0;
//    }
//    c[1]=1;
//    d[1]=0;
//}
//void dijkstra(void) {
//    int i,v,w;
//    ii x;
//    priority_queue<ii,vii,greater<ii> > q;
//    q.push(ii(0,1));
//    while (!q.empty()) {
//        x=q.top(); q.pop();
//        w=x.first;
//        v=x.second;
//        for (i=0;i<g[v].size();i=i+1) {
//            if (d[g[v][i].first]==w+g[v][i].second) {
//                c[g[v][i].first]+=c[v];
//                continue;
//            }
//            if (d[g[v][i].first]>w+g[v][i].second) {
//                d[g[v][i].first]=w+g[v][i].second;
//                c[g[v][i].first]=c[v];
//                q.push(ii(d[g[v][i].first],g[v][i].first));
//                continue;
//            }
//        }
//    }
//    printf("%d %lld",d[n],c[n]);
//}
//int main(void) {
//    loadgraph();
//    dijkstra();
//}
