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
const int MOD=1000000003;
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

int a[1001][1001],indeg[1001],visit[1001],dp[1001],val[1001];
vi topo;

void dfs(int u)
{
    visit[u]=1;
    for (int v='A';v<='Z';v++)
    {
        if (a[u][v] && !visit[v])
            dfs(v);
    }
    topo.pb(u);
}

signed main()
{
    freopen("452.INP","r",stdin);
    freopen("452.OUT","w",stdout);
    int tests;
    cin>>tests;
    while (tests--)
    {
        memset(a,0,sizeof a);
        memset(indeg,0,sizeof indeg);
        memset(visit,0,sizeof visit);
        memset(dp,0,sizeof dp);
        memset(val ,0, sizeof val);

        topo.clear();
        vector<char> l;
        char c;
        int w;
        cin>>c>>w;
        l.pb(c);
        val[c]=w;
        string s;
        cin>>s;
        for (int i=0;i<sz(s);i++)
        {
            char x=s[i];
            a[c][x]=1;
            indeg[x]++;
        }

        for (auto i: l)
            if (indeg[i]==0) dfs(i);

        int u=topo[sz(topo)-1];
        dp[u]=val[u];
        for (int i=sz(topo)-1;i>=0;i--)
        {
            int u=topo[i];
            for (int v='A';v<='Z';v++)
            {
                if (a[u][v])
                {
                    dp[v]=max(dp[u]+val[v],dp[v]);
                }
            }
        }
        cout<<dp[topo[0]]<<endl;
    }
}
