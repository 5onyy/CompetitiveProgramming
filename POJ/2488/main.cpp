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

ll ans=-1;
int n,m;
int par[20001];
struct node
{
    int u,v;
    ll w;
    node (int u,int v,ll w)
    {
        this->u=u;
        this->v=v;
        this->w=w;
    }
};

bool cmp(const node &x, const node &y)
{
    return x.w<y.w;
}

int root(int v)
{
    return par[v]<0 ? v : (par[v]=root(par[v]));
}

bool join (int u,int v)
{
    if ((u=root(u))==(v=root(v)))
        return false;
    if (par[v]<par[u])
        swap(u,v);
    par[u]+=par[v];
    par[v]=u;
}

vector<node> a;


int main()
{
    freopen("2488.INP","r",stdin);
    freopen("2488.OUT","w",stdout);
    memset(par,-1,sizeof par);
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        int t1,t2;
        ll w;
        cin>>t1>>t2>>w;
        a.pb(node(t1,t2,w));
    }
    sort(a.begin(),a.end(),cmp);
    for (int i=0;i<sz(a);i++)
    {
        if (join(a[i].u,a[i].v))
            ans=max(ans,a[i].w);
    }
    cout<<ans;
}
