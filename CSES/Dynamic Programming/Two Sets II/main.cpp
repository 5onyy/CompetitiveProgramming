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
const int MOD=1000000007;
const int d4i[4]= {-1, 0, 1, 0}, d4j[4]= {0, 1, 0, -1};
const int d8i[8]= {-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]= {0, 1, 1, 1, 0, -1, -1, -1};

int dp[62626][maxN];
int n;

signed main()
{
//    freopen(".INP","r",stdin);
//    freopen(".OUT","w",stdout);
    cin>>n;
    int w=n*(n+1)/4;
    dp[0][0]=1;
    for (int j=1; j<=n; j++)
    {
        for (int i=1; i<=w; i++)
        {
            if (i-j>=0)
                dp[i][j]=(dp[i-j][j-1]+dp[i][j-1])%MOD;
            else dp[i][j]=(dp[i][j]+dp[i][j-1])%MOD;
        }

    }
    if ((n*(n+1))%4==0)
        cout<<dp[w][n];
    else cout<<0;
}
