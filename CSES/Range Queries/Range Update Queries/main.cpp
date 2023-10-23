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

const int maxN=3*1e5+1;
const int BASE=311;
const int N=1e5+5;
const int MOD=1000000003;
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

int n,q;
ll a[maxN],st[4*maxN],p[maxN];

void update(int l,int r,int u,ll val,int id)
{
    if (u>r || u<l)
        return;
    if (l==r && l==u)
    {
        st[id]+=val;
        return;
    }
    int mid=(l+r)>>1;
    update(l,mid,u,val,id*2);
    update(mid+1,r,u,val,id*2+1);
    st[id]=st[id*2]+st[id*2+1];
}

ll get(int l,int r,int u,int v,int id)
{
    if (u>r || v<l)
        return 0;
    if (l>=u && r<=v)
        return st[id];
    int mid=(l+r)>>1;
    return (get(l,mid,u,v,id*2)+get(mid+1,r,u,v,id*2+1));
}

signed main()
{
    //hardio("test");
    fastIO;
    cin>>n>>q;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        p[i]=a[i]-a[i-1];
        update(1,n,i,a[i]-a[i-1],1);
    }
//    for (int i=0;i<=4*n;i++)
//        cout<<st[i]<<" ";
//    cout<<endl;
//    cout<<get(1,n,1,5,1);
    while (q--)
    {
        int k;
        cin>>k;
        if (k==2)
        {
            int u;
            cin>>u;
            cout<<get(1,n,1,u,1)<<endl;
        }
        else{
            int u,v;
            ll x;
            cin>>u>>v>>x;
            update(1,n,u,x,1);
            update(1,n,v+1,-x,1);
        }

    }
}
