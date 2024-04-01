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
const int d4i[4]= {-1, 0, 1, 0}, d4j[4]= {0, 1, 0, -1};
const int d8i[8]= {-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]= {0, 1, 1, 1, 0, -1, -1, -1};

int n;
int a[maxN],present[maxN],st[4*maxN];

void build (int l,int r,int id)
{
    if (l==r)
    {
        st[id]=1;
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,id*2);
    build(mid+1,r,id*2+1);
    st[id]=st[id*2]+st[id*2+1];
}

void update(int l,int r,int k,int val,int id)
{
    if (k<l || k>r)
        return;
    if (l==r && l==k)
    {
        st[id]=val;
        return;
    }
    int mid=(l+r)>>1;
    update(l,mid,k,val,id*2);
    update(mid+1,r,k,val,id*2+1);
    st[id]=st[id*2]+st[id*2+1];
}

ll getsum(int l,int r,int u,int v,int id)
{
    if (v<l || u>r)
        return 0;
    if (l>=u && r<=v)
        return st[id];
    int mid=(l+r)>>1;
    return getsum(l,mid,u,v,id*2)+getsum(mid+1,r,u,v,id*2+1);
}

signed main()
{
    //hardio("t");
    fastIO;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    build(1,n,1);
    vi present(n+1,1);

    for (int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        //cout<<"x: "<<x<<endl;
        int lo=1,hi=n;
        while (lo<=hi)
        {
            int mid=(hi+lo)/2;
            int s_mid=getsum(1,n,1,mid,1);
//            cout<<"sum: "<<s_mid<<endl;
//            cout<<"mid: "<<mid<<endl;
//            cout<<"lo: "<<lo<<endl;
//            cout<<"hi: "<<hi<<endl;
            if (s_mid<x)
                lo=mid+1;
            else if (s_mid>x)
                hi=mid-1;
            else
            {
                if (present[mid])
                {
                    present[mid]=0;
                    cout<<a[mid]<<" ";
//                    for (int i=1;i<=n;i++)
//                        cout<<present[i]<<" ";
//                    cout<<endl;
                    update(1,n,mid,0,1);
                    break;
                }
                else   hi=mid-1;
            }
            //cout<<endl;
        }
        //cout<<endl;
    }
}
