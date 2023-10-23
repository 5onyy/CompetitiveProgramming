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

int n,l,r,s;
vii a;

bool check(int s)
{
    for (int i=0;i<n;i++)
    {
        auto vt=lower_bound(a.begin(),a.end(),ii(s-a[i].fi,0));
        int t=vt-a.begin();
        if (a[t].fi==s-a[i].fi && (t!=i))
        {l=a[i].se;   r=a[t].se;    return true;}
    }
    return false;
}

int main()
{
//    freopen(".INP","r",stdin);
//    freopen(".OUT","w",stdout);
    cin>>n>>s;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a.pb(ii(x,i));
    }
    sort(a.begin(),a.end());
    if (check(s))   cout<<l+1<<" "<<r+1;
    else cout<<"IMPOSSIBLE";
}
