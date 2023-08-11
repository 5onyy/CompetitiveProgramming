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

int a[2000000],k,n,ans;

bool check(int mid)
{
    int tmp=0;
    for (int i=n/2;i<n;i++)
        tmp+=max(0ll,mid-a[i]);
    if (tmp<=k) return 1;
    return 0;
}

signed main()
{
//    freopen(".INP","r",stdin);
//    freopen(".OUT","w",stdout);
    cin>>n>>k;
    for (int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int l=0,r=2000000000;
    while (l<r)
    {
        int mid=(l+r+1)/2;
        if (check(mid))
            l=mid,ans=mid;
        else r=mid-1;
    }
    cout<<ans;
}
