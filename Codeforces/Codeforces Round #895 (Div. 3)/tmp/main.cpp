#include <bits/stdc++.h>

using namespace std;

template<typename T>
using vt = vector<T>;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
using vi = vt<int>;
using vii = vt<ii>;
using vll = vt<ll>;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 200010;
const ll MOD = 998244353;
const double eps = 1e-12;

ll fgcd(ll a, ll b)
{
    while(b) swap(b, a %= b);
    return a;
}
ll fpow(ll a, ll b, const ll c)
{
    ll ans = 1;
    a %= c;
    for(; b; b >>= 1, a = a * a % c) if(b & 1) ans = ans * a % c;
    return ans;
}
ll fpow(ll a, ll b)
{
    ll ans = 1;
    for(; b; b >>= 1, a *= a) if(b & 1) ans *= a;
    return ans;
}
int flog(int x)
{
    return 31 - __builtin_clz(x);
}
int flog(ll x)
{
    return 63 - __builtin_clzll(x);
}

#define debug(x) { cout << #x << " = "; cout << (x) << endl; }

void setIO(string name)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    if (!name.size()) return;

#ifndef ONLINE_JUDGE
    freopen((name + ".inp").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
#endif
}

void sieve(int N)
{
    bool isPrime[N+1];
    for(int i = 0; i <= N; ++i)
    {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i * i <= N; ++i)
    {
        if(isPrime[i] == true)
        {
            // Mark all the multiples of i as composite numbers
            for(int j = i * i; j <= N; j += i)
                isPrime[j] = false;
        }
    }
}

const int N = 2e4;

int n,m;
int dp[N],a[N],pref[N];

int main()
{
    setIO("");
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        pref[i] = pref[i-1] + ((a[i] >= m) ? 1 : 0);
    }
    //for (int i=1;i<=n;i++)  cout<<pref[i]<<' ';
    //cout<<'\n';
    for (int i=1; i<=n; i++)
    {
        for (int j=i; j>=1; j--)
        {
            if (pref[i] - pref[j-1]  >= (i-j+1)/2+1 && (dp[j-1]||j-1==0))    dp[i] =  max(dp[i], dp[j-1]+1);
        }
    }
    cout<<dp[n]<<'\n';;
    //for (int i=1;i<=n;i++) cout<<dp[i]<<' ';
    return 0;
}

//   _                          _
//  | |__   ___ _ __ ___  _   _| |_
//  | '_ \ / __| '_ ` _ \| | | | __|
//  | | | | (__| | | | | | |_| | |_
//  |_| |_|\___|_| |_| |_|\__,_|\__|
