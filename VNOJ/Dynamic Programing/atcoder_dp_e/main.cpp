#include<bits/stdc++.h>

using namespace std;

#define fastIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mp make_pair
#define inf 2000000000
#define sz(x) (int)(x).size()
#define double long double
#define log2(x)        log(x)/log(2.0)
#define hardio(x)      freopen(x".inp","r",stdin), freopen(x".out","w",stdout);
#define rall(x)        x.rbegin(),x.rend()

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int maxN=1001;
const int BASE=311;
const int N=1e3+1;
const int MOD=1000000003;
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

int n,w;
int dp[101][N];
int a[101],b[101];

signed main()
{
    fastIO;
    cin>>n>>w;
    for (int i=1;i<=n;i++)
        cin>>a[i]>>b[i];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=N;j++)
            dp[i][j]=inf;
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<=N;j++)
        {
            if (dp[i][j]+a[i]<=w)
                dp[i][j]=min(dp[i-1][j-b[i]]+a[i],dp[i][j]);
            else dp[i][j]=dp[i-1][j];
        }
    }
    for (int i=N;i>=0;i--)
    {
        if (dp[n][i]!=inf)
        {
            cout<<i;
            break;
        }
    }
}
