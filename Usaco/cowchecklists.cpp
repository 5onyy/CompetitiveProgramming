#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define sqr(x) ((x) * (x))
#define log2i(x) (64 - __builtin_clzll(1ll * (x)) - 1)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define debug(x)             \
    {                        \
        cout << #x << " = "; \
        cout << (x) << endl; \
    }
#define rr(x) sort(all(x)), x.resize((unique(all(x)) - x.begin()));

template <typename T>
using vt = vector<T>;
using ll = long long;
using ld = long double;
using vi = vt<int>;
using ii = pair<int, int>;
using vii = vt<ii>;

const ll INF = 4e18;
const int inf = INT_MAX;
const int MOD = 1000000003;
const int d4i[4] = {-1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
const int d8i[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};

template <class U, class V>
std::ostream &operator<<(std::ostream &out, const std::pair<U, V> &p) { return out << '(' << p.first << ", " << p.second << ')'; } // cout pair type
template <typename T>
using minpq = priority_queue<T, vt<T>, greater<T>>;
template <typename T>
using maxpq = priority_queue<T>;

ll fgcd(ll a, ll b)
{
    while (b)
        swap(b, a %= b);
    return a;
}
ll fpow(ll a, ll b, const ll c)
{
    ll ans = 1;
    a %= c;
    for (; b; b >>= 1, a = a * a % c)
        if (b & 1)
            ans = ans * a % c;
    return ans;
}
ll fpow(ll a, ll b)
{
    ll ans = 1;
    for (; b; b >>= 1, a *= a)
        if (b & 1)
            ans *= a;
    return ans;
}
int flog(int x) { return 31 - __builtin_clz(x); }
int flog(ll x) { return 63 - __builtin_clzll(x); }

void setIO(string name)
{
    cin.tie(0)->sync_with_stdio(0);
    if (sz(name))
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

const int N = 1e3+5;

ll dp[N][N][2];

ll dist(ii a, ii b){
    return sqr(a.fi-b.fi) + sqr(a.se-b.se);
}

int main()
{
    setIO("checklist");
    int n, m;
    cin >> n >> m;
    //cout<<n<<' '<<m;
    vii h(n+1), g(m+1);
    for (int i=1;i<=n;i++)  cin>>h[i].fi>>h[i].se;
    for (int j=1;j<=m;j++)  cin>>g[j].fi>>g[j].se;
    for (int i=0;i<=n;i++) for (int j=0;j<=m;j++)   for (int k=0;k<2;k++)   dp[i][j][k] = INF;
    dp[1][0][0] = 0;
    g[0] = {0,0};   h[0] = {0,0};
    for (int i=0;i<=n;i++){
        for (int j=0;j<=m;j++){
            for (int k=0;k<2;k++){
                if (k==0 && i){
                    dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][k] + dist(h[i-1],h[i]));
                    dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][k^1] + dist(g[j],h[i]));
                }
                else if (k==1 && j){
                    dp[i][j][k] = min(dp[i][j][k], dp[i][j-1][k] + dist(g[j-1],g[j]));
                    dp[i][j][k] = min(dp[i][j][k], dp[i][j-1][k^1] + dist(g[j],h[i]));
                    //if (i==1 && j==1 && k==1)   debug(dp[1][1][1]);
                }
            }
        }
    }
    //debug(dp[1][0][0]);
    cout<<dp[n][m][0]; 
    return 0;
}

/*g++ -std=c++17 -O2 -Wall ".cpp" -o main.exe
./main.exe*/