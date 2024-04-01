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

int n,m,u,v,w;
vector<vii> a;
int d[1001];

void dijkstra(int s)
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
            {
                d[v]=d[u]+w;
                q.push(ii(w,v));
            }
        }
    }
}

int main()
{
    freopen("1125.INP","r",stdin);
    freopen("1125.OUT","w",stdout);
    while (cin>>n && n)
    {
        ii ans=(ii(inf,inf));
        a.clear();
        a.resize(n+1);
        for (int u=1;u<=n;u++)
        {
            cin>>m;
            for (int i=0;i<m;i++)
            {
                cin>>v>>w;
                a[u].pb(ii(v,w));
            }
        }
        for (int i=1;i<=n;i++)
        {
            dijkstra(i);
            int tmp=0;
            for (int i=1;i<=n;i++)
            {
                if (tmp<d[i])
                    tmp=d[i];
            }
            if (ans.fi>tmp)
                ans=ii(tmp,i);
        }
        if (ans.se == inf)  cout<<"disjoint"<<endl;
        else cout<<ans.se<<" "<<ans.fi<<endl;
    }
}
