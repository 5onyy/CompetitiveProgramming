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
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

string a,b;
int dp[5000][5000],trace[5000];
int k=0,mm;

signed main()
{
    fastIO;
    cin>>a>>b;
    a=" "+a;
    b=" "+b;
    int n=sz(a),m=sz(b);
    for (int i=1;i<n;i++)
    {
        for (int j=1;j<m;j++)
        {
            if (a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    string ans="";
    n--;
    m--;
    while (n && m)
    {
        if (a[n]==b[m])
        {
            ans=a[n]+ans;
            n--;
            m--;
        }
        else if (dp[n-1][m]>dp[n][m-1]) n--;
        else m--;
    }
    cout<<ans;
}
