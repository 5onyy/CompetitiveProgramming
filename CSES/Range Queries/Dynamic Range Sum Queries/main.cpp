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

int n,q;
ll a[maxN];
pair<ll,ll> st[4*maxN];

void build (int l,int r,int id)
{
    if (l==r)
    {
        st[id].se+=a[l];   return;
    }
    int mid =(l+r)>>1;
    build(l,mid,id*2);
    build(mid+1,r,id*2+1);
    st[id].se=st[id*2].se+st[id*2+1].se;
}

void down(int id,int l,int r){
    ll t=st[id].fi;
    int mid=(l+r)>>1;
    st[id*2].fi+=t;
    st[id*2].se+=(mid-l+1)*t;

    st[id*2+1].fi+=t;
    st[id*2+1].se+=(r-mid)*t;

    st[id].fi=0;
}

void update(int l,int r,int u, int v,int id,ll val)
{
    if (v<l || u>r)
        return;
    if (l>=u && r<=v)
    {
        st[id].se+=(r-l+1)*val;
        st[id].fi+=val;
        return;
    }
    int mid=(l+r)>>1;
    down(id,l,r);
    update(l,mid,u,v,id*2,val);
    update(mid+1,r,u,v,id*2+1,val);
    st[id].se=st[id*2].se+st[id*2+1].se;
}

ll getsum(int l,int r,int u,int v,int id)
{
    if (v<l || u>r)
        return 0;
    if (l>=u && r<=v)
       return st[id].se;
    down(id,l,r);
    int mid=(l+r)>>1;
    return getsum(l,mid,u,v,id*2)+getsum(mid+1,r,u,v,id*2+1);
}

signed main()
{
    hardio("QUERY");
    fastIO;
    cin>>n>>q;
//    for (int i=1;i<=n;i++)
//        cin>>a[i];
//    build(1,n,1);
    while (q--)
    {
        ll k,u,v;
        cin>>k>>u>>v;
        if (k==1)
        {
            ll val;
            cin>>val;
            update(1,n,u,v,1,val);
        }
        else cout<<getsum(1,n,u,v,1)<<endl;
    }


}
