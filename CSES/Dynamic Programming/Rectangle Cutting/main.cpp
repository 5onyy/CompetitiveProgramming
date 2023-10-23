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
const int inf=1e9;
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

int n,m;
int dp[501][501];

int main(){
    setIO("");
    cin>>n>>m;
    for (int i=1;i<=500;i++)  for (int j=1;j<=500;j++)  if (i!=j) dp[i][j]=inf;
        dp[0][0]=0;
    dp[1][1]=0;
    for (int i=2;i<=m;i++)  dp[1][i]=dp[1][i-1]+1;
    for (int i=2;i<=n;i++)  dp[i][1]=dp[i-1][1]+1;
    for (int i=2;i<=n;i++){
        for (int j=2;j<=m;j++){
            for (int w=1;w<=max(n,m);w++){
                if (i>=w)   dp[i][j]=min(dp[i][j], dp[i-w][j]+dp[w][j]+1);
                if (j>=w)   dp[i][j]=min(dp[i][j], dp[i][j-w]+dp[i][w]+1);
            }

        }
        //cout<<endl;
    }
//    for (int i=1;i<=n;i++){
//        for (int j=1;j<=m;j++)  cout<<dp[i][j]<<' ';
//        cout<<'\n';
//    }
    cout<<dp[n][m];
}
