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
#define hardio(x)      freopen(x".inp","r",stdin), freopen(x".out","w",stdout);
#define rall(x)        x.rbegin(),x.rend()

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int maxN=1001;
const int BASE=311;
const int N=1e5+5;
const int MOD=1000000003;
const int d4i[4]= {-1, 0, 1, 0}, d4j[4]= {0, 1, 0, -1};
const int d8i[8]= {-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]= {0, 1, 1, 1, 0, -1, -1, -1};

int a[105],b[105];
int dp[105][N];
int n,w,ans=-1;

signed main()
{
//        #ifndef ONLINE_JUDGE
//    hardio("digitssum");
//    #endif
    fastIO;
    cin>>n>>w;
    for (int i=1; i<=n; i++)
        cin>>a[i]>>b[i];
    for (int i=1; i<=n; i++)
    {
        for (int k=0; k<=w; k++)
        {
            if (k>=a[i])
            {
                    dp[i][k]=max(dp[i-1][k-a[i]]+b[i],dp[i][k]);
                    ans=max(ans,dp[i][k]);
            }
            dp[i][k]=max(dp[i-1][k],dp[i][k]);
        }
    }
//    for (int i=1; i<=n; i++)
//    {
//        for (int j=1; j<=w; j++)
//            cout<<dp[i][j]<<" ";
//        cout<<endl;
//    }
    cout<<ans;
}
