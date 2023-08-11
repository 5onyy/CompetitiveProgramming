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

int n;
int a[100001],dp[100001];

signed main()
{
//    freopen("VANCHUYEN.INP","r",stdin);
//    freopen("VANCHUYEN.OUT","w",stdout);
    fastIO;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    dp[1]=0;
    dp[2]=abs(a[2]-a[1]);
    for (int i=3;i<=n;i++)
        dp[i]=min(dp[i-2]+abs(a[i]-a[i-2]),dp[i-1]+abs(a[i]-a[i-1]));
    cout<<dp[n];
//    for (int i=1;i<=n;i++)
//        cout<<dp[i]<<" ";
}
