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
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int dist(ii x, ii y){
    return sqr(x.fi-y.fi) + sqr(x.se-y.se);
}

int main(){
    setIO("checklist");
    int n,m;
    cin>>n>>m;
    vector<vt<ll>> dp(n+1,vt<ll>(m+1,0));
    vii h(n+1),g(m+1);
    for (int i=1;i<=n;i++)  cin>>h[i].fi >> h[i].se;
    for (int j=1;j<=m;j++)  cin>>g[j].fi >> g[j].se;
    g[0] = {inf,inf};   h[0] = {inf,inf};
    for (int i=1;i<=n;i++)  for (int j=1;j<=m;j++)  dp[i][j] = inf;
    for (int i=1;i<=n;i++){
        for (int j=0;j<=m;j++)  {
            dp[i][j] = dp[i-1][j] + (dist(h[i],h[i-1]),dist(g[j],h[i]));
            if (j>0)    dp[i][j] = min(dp[i][j], dp[i][j-1] + min(dist(g[j-1],g[j]),dist(g[j],h[i]) ));
        }
    }  
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++)  cout<<dp[i][j]<<' ';
        cout<<'\n';
    }
    cout<<dp[n][m];
}

/*g++ -std=c++17 -O2 -Wall "main.cpp" -o main.exe 
./main.exe*/