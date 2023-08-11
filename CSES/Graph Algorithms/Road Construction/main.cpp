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

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int BASE=311;
const int MOD=1000000003;
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

vi par;
int n,m,cur,ans=inf;

int root(int v)
{
    return (par[v]<0) ? v: (par[v]=root(par[v]));
}

bool join(int x,int y)
{
    if ((x=root(x))==(y=root(y)))   return 0;
    if (par[x]>par[y])  swap(x,y);
    par[x]+=par[y];
    par[y]=x;
    ans=min(ans,min(par[x],par[y]));
    return 1;
}

signed main()
{
//    freopen(".INP","r",stdin);
//    freopen(".OUT","w",stdout);
    cin>>n>>m;
    cur=n;
    par.assign(n+1,-1);
    for (int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        if (join(x,y))   cur--;
        cout<<cur<<" ";
        cout<<-ans<<endl;
    }
}
