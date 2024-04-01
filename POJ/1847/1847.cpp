#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

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

int n,s,t,m,v;
vector<vii> a;
int d[1001];

void djikstra(int s)
{
    for (int i=1;i<=n;i++)
        d[i]=inf;
    priority_queue<ii, vector<ii>, greater<ii> > q;
    q.push(ii(0,s));
    d[s]=0;
    while (!q.empty())
    {
        int u=q.top().se;
        q.pop();
        for (int i=0;i<sz(a[u]);i++)
        {
            int v=a[u][i].fi;
            int w=a[u][i].se;
            if (d[v]>d[u]+w)
                d[v]=d[u]+w,    q.push(ii(d[v],v));
        }
    }
}

int main()
{
    freopen("1847.INP","r",stdin);
    freopen("1847.OUT","w",stdout);
    cin>>n>>s>>t;
    a.resize(n+1);
    for (int u=1;u<=n;u++)
    {
        cin>>m;
        for (int i=1;i<=m;i++)
        {
            cin>>v;
            if (i==1)   a[u].pb(ii(v,0));
            else a[u].pb(ii(v,1));
        }
    }
    djikstra(s);
    if (d[t]==inf)  cout<<-1;
    else cout<<d[t];
}
