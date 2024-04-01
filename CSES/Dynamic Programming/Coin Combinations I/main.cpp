#include <iostream>

using namespace std;

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
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

int n,x;
int dp[1000001],coin[100];

signed main()
{
//    freopen(".INP","r",stdin);
//    freopen(".OUT","w",stdout);
    cin>>n>>x;
    for (int i=0;i<n;i++)
        cin>>coin[i];
    dp[0]=1;
    for (int i=1;i<=x;i++)
        for (int k=0;k<n;k++)
            if (i-coin[k]>=0)
                dp[i]=(dp[i]+dp[i-coin[k]])%MOD;
    cout<<dp[x];
}
