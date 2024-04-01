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
typedef pair<int,int> ii;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ii> vii;

const ll BASE=311;
const ll MOD=1000000003;
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

int n,m;
vector<vi> a;
vi d,trace,ans;
int visit[100001];

void bfs(int s)
{
    queue<int> q;
    d[s]=1;
    trace[s]=-1;
    visit[s]=1;
    q.push(s);
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        for (int i=0;i<sz(a[u]);i++)
        {
            int v=a[u][i];
            if (!visit[v])
                {visit[v]=1;  d[v]=d[u]+1;    trace[v]=u; q.push(v);}
        }
    }
}

int main()
{
//    freopen(".INP","r",stdin);
//    freopen(".OUT","w",stdout);
    cin>>n>>m;
    a.resize(n+1,vi());
    d.assign(n+1,inf);
    trace.resize(n+1);
    for (int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        a[v].pb(u);
        a[u].pb(v);
    }
    bfs(1);
    if (d[n]==inf) cout<<"IMPOSSIBLE";
    else
    {
        cout<<d[n]<<endl;
        int tmp=n;
//        ans.pb(tmp);
        while (tmp!=-1)
        {
            ans.pb(tmp);
            tmp=trace[tmp];
        }
        for (int i=sz(ans)-1;i>=0;i--)
            cout<<ans[i]<<" ";
    }
}
