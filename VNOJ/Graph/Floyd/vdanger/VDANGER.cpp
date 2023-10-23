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

int a[101][101];
int n,m,ans;
vi way;

int main()
{
    freopen("VDANGER.INP","r",stdin);
    freopen("VDANGER.OUT","w",stdout);
    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
        int t;
        cin>>t;
        way.pb(t);
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            cin>>a[i][j];
    for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                a[i][j]=min(a[i][k]+a[k][j],a[i][j]);
    for (int i=0;i<m-1;i++)
    {
        ans+=a[way[i]][way[i+1]];
    }
    cout<<ans;
    return 0;
}
