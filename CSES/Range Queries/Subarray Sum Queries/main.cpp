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

int n,m,k,x;
int a[200001];

struct node{
    int g_max, l_max, r_max, sum;
	node operator +(node b) {
		return {
			max(max(g_max, b.g_max), r_max + b.l_max),
			max(l_max, sum + b.l_max),
			max(b.r_max, r_max + b.sum),
			sum + b.sum
		};
	}
} st[4000000];

void build(int l,int r,int id)
{
    if (l==r)
    {
        st[id]={max(0ll, a[l]), max(0ll, a[l]), max(0ll, a[l]), a[l]};
        return;
    }
    int mid=(l+r)/2;
    build(l,mid,id*2);
    build(mid+1,r,id*2+1);
    st[id]=st[id*2]+st[id*2+1];
}

void update(int pos,int val,int l,int r,int id)
{
    if (l==r)
    {
        st[id]={max(0ll, val), max(0ll, val), max(0ll, val), val};
        return;
    }
    int mid=(l+r)/2;
    if (pos>mid) update(pos,val,mid+1,r,id*2+1);
    else update(pos,val,l,mid,id*2);
    st[id]=st[id*2]+st[id*2+1];
}

signed main()
{
//    freopen(".INP","r",stdin);
//    freopen(".OUT","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    build(1,n,1);
    while (m--)
    {
        cin>>k>>x;
        update(k,x,1,n,1);
        cout<<st[1].g_max<<endl;
    }
}
