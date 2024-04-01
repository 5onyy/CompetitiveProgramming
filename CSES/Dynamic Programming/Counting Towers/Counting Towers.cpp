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
const int d4i[4]= {-1, 0, 1, 0}, d4j[4]= {0, 1, 0, -1};
const int d8i[8]= {-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]= {0, 1, 1, 1, 0, -1, -1, -1};
const ll mod=1e9+7;

ll dp[1000002][2];

int main()
{
//    freopen("1.INP","r",stdin);
//    freopen("1.OUT","w",stdout);
    fastIO;

    dp[1][0]=dp[1][1]=1;
    for (int i=2; i<=1000000; i++)
    {
        ll op1=(dp[i-1][0]+dp[i-1][1]) % mod;
        ll op2=dp[i-1][0];
        ll op3=(2*dp[i-1][0]) % mod;
        ll op4=dp[i-1][1];
        dp[i][0]=(op1 + op2 + op3) % mod;
        dp[i][1]=(op1 + op4) % mod;
    }

    int tests;
    cin>>tests;
    while (tests--)
    {
        int n;
        cin>>n;
        cout<<(dp[n][0]+dp[n][1])% mod<<endl;
    }
    return 0;
}
