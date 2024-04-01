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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> ii;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ii> vii;

const ll BASE=311;
const ll MOD=1000000003;
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

int n,m;
int visit[100001],color[100001];
vector<vi> a;
vii ed;
bool ok=true;

void dfs(int u,int c)
{
    visit[u]=1;
    color[u]=c;
    for (int v:a[u])
    {
        if (!visit[v]) dfs(v,1-c);
    }
}

int main()
{
//    freopen(".INP","r",stdin);
//    freopen(".OUT","w",stdout);
    cin>>n>>m;
    a.resize(n+1,vi());
    for (int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        a[u].pb(v);
        a[v].pb(u);
        ed.pb(ii(u,v));
    }
    for (int i=1;i<=n;i++)
        if (!visit[i])  dfs(i,0);
    for (int i=0;i<m;i++)
    {
        if (color[ed[i].fi]==color[ed[i].se])
            {   ok=false;   break;  }
    }
    if (!ok) cout<<"IMPOSSIBLE";
    else
    {
        for (int i=1;i<=n;i++)
            cout<<color[i]+1<<" ";
    }
}

