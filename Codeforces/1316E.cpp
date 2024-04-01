#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define sqr(x) ((x) * (x))
#define log2i(x) (64 - __builtin_clzll(1ll * (x)) - 1)
#define all(x)         x.begin(),x.end()
#define rall(x)        x.rbegin(),x.rend()
#define debug(x) { cout << #x << " = "; cout << (x) << endl; }
#define rr(x)          sort(all(x)),x.resize((unique(all(x))-x.begin()));

template<typename T> using vt = vector<T>;
using ll = long long;
using ld = long double;
using vi = vt<int>;
using ii = pair<int, int>;
using vii = vt<ii>;

const ll INF=4e18;
const int inf=INT_MAX;
const int MOD=1000000003;
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

template<class U, class V> std::ostream& operator << (std::ostream& out, const std::pair<U, V>& p) {return out << '(' << p.first << ", " << p.second << ')';}   //cout pair type
template<typename T> using minpq = priority_queue<T, vt<T>,greater<T>>;
template<typename T> using maxpq = priority_queue<T>;

ll fgcd(ll a, ll b) {while(b) swap(b, a %= b); return a;}
ll fpow(ll a, ll b, const ll c) { ll ans = 1; a %= c; for(; b; b >>= 1, a = a * a % c) if(b & 1) ans = ans * a % c; return ans;}
ll fpow(ll a, ll b) {ll ans = 1; for(; b; b >>= 1, a *= a) if(b & 1) ans *= a; return ans;}
int flog(int x) {return 31 - __builtin_clz(x);}
int flog(ll x) {return 63 - __builtin_clzll(x);}

void setIO(string name) {
    cin.tie(0)->sync_with_stdio(0);
    if(sz(name)) {
        freopen((name+".inp").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

const int N = 2e5 + 5;

int a[N];
int s[N][7];
ll dp[N][1<<7];

int main(){
    setIO("");
    int n,p,k;
    cin>>n>>p>>k;
    memset(dp,-1,sizeof dp);
    for (int i=0;i<n;i++)   cin>>a[i];
    for (int i=0;i<n;i++)   for (int j=0;j<p;j++)   cin>>s[i][j];   
    vi ids(n,0);    iota(ids.begin(),ids.end(),0);
    sort(ids.begin(),ids.end(), [&] (int u,int v){
        return a[u] > a[v];
    });
    dp[0][0] = 0;
    for (int i=1;i<=ids.size();i++){
        for (int S=0;S<(1<<p);S++){
            int cnt = __builtin_popcount(S);
            int rem = i-1 - cnt;
            if (rem < k && dp[i-1][S]!=-1)    dp[i][S] = dp[i-1][S] + a[ids[i-1]];
            else if (dp[i-1][S]!=-1) dp[i][S] = dp[i-1][S];
            for (int j=0;j<p;j++){
                if (~S & (1<<j))    continue;
                if (dp[i-1][S^(1<<j)]!=-1)  dp[i][S] = max(dp[i][S],dp[i-1][S^(1<<j)] + s[ids[i-1]][j]);
            }
        }
    }
    cout<<dp[n][(1<<p)-1];
}