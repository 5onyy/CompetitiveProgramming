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
const int N=1e3+5;
const int MOD=1000000003;
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

int dp[N][N];
int n,m;
char a[N][N];
const int mod=1e9+7;

signed main()
{
    fastIO;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for (int j=1;j<=m;j++)
            a[i][j]=s[j-1];
    }
    dp[1][1]=1;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (a[i][j]!='#')
            {
                if (a[i-1][j] !='#')
                    dp[i][j] = (dp[i][j]+ dp[i-1][j]) %(mod);
                if (a[i][j-1]!='#')
                    dp[i][j] = (dp[i][j] + dp[i][j-1]) % (mod);
            }
        }
    }
    cout<<dp[n][m];
}
