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

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;

const int maxN=2*1e5+1;
const int BASE=311;
const int N=1e5+5;
const int MOD=1000000003;
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

int st[4*maxN],a[maxN];
int n,q;

void build(int l,int r,int id)
{
    if (l==r)
    {
        st[id]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,id*2);
    build(mid+1,r,id*2+1);
    st[id]=(st[id*2] ^ st[id*2+1]);
}

int getxor(int l,int r,int u,int v,int id)
{
    if (u>r || v<l)
        return 0;
    if (l>=u && r<=v)
        return st[id];
    int mid=(l+r)>>1;
    return (getxor(l,mid,u,v,id*2) ^ getxor(mid+1,r,u,v,id*2+1));
}

signed main()
{
    //hardio("t");
    fastIO;
    cin>>n>>q;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    build (1,n,1);
    while (q--)
    {
        int u,v;
        cin>>u>>v;
        cout<<getxor(1,n,u,v,1)<<endl;
    }
}
