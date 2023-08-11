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

int n,m,ans;
vi par;

struct node{
    int u,v,w;
    node (int u,int v,int w)
    {
        this->u=u;
        this->v=v;
        this->w=w;
    }
};

bool operator>(const node &a, const node &b)
{
    return a.w>b.w;
}

int root (int v)
{
    return par[v]<0? v : (par[v]=root(par[v]));
}

bool join(int x,int y)
{
    if ((x=root(x))==(y=root(y)))
        return false;
    if (par[y]<par[x])
        swap(x,y);
    par[x]+=par[y];
    par[y]=x;
    return true;
}

int main()
{
    freopen("QBMST.INP","r",stdin);
    freopen("QBMST.OUT","w",stdout);
    cin>>n>>m;
    par.assign(n+1,-1);
    priority_queue<node, vector<node>,greater<node> > q;
    for (int i=0;i<m;i++)
    {
        int t1,t2,w;
        cin>>t1>>t2>>w;
        q.push(node(t1,t2,w));
    }
    int d=0;
    while (d!=n-1)
    {
        node tmp=q.top();
        q.pop();
        if (join(tmp.u,tmp.v))
            d++, ans+=tmp.w;
    }
    cout<<ans;
}
