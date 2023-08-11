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

vii a;
int n,ans,s;

int main()
{
//    freopen("1.INP","r",stdin);
//    freopen("1.OUT","w",stdout);
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        a.pb(ii(t1,1));
        a.pb(ii(t2,-1));
    }
    sort(a.begin(),a.end());
    for (int i=0;i<sz(a);i++)
    {
        s+=a[i].se;
        ans=max(ans,s);
    }
    cout<<ans;
}
