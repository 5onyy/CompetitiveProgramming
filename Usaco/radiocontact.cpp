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

ii operator + (ii a, ii b) {
    return {a.fi + b.fi, a.se + b.se};
}

ii operator - (ii a, ii b) {
    return {a.fi - b.fi, a.se - b.se};
}

const int N=1e3+5;
ll dp[N][N];

ll dist(ii a, ii b){
    return sqr(a.fi-b.fi) + sqr(a.se-b.se);
}

ii newloc(ii a, char c){
    ii x;
    if (c == 'N')   x = ii(0,1);
    if (c == 'E')   x = ii(+1,0);
    if (c == 'W')   x = ii(-1,0);
    if (c == 'S')   x = ii(0,-1);
    return x + a;
}

int main()
{
    setIO("radio");
    int n,m;
    cin>>n>>m;
    ii x1,y1; cin>>x1.fi>>x1.se;    cin>>y1.fi>>y1.se;
    string jo,be;
    cin>>jo>>be;
    ii curx = x1;
    ii cury = y1;
    for (int i=0;i<=n;i++)  for (int j=0;j<=m;j++)  dp[i][j] = INF;
    dp[0][0] = 0;
    for (int i=0;i<=n;i++){
        ii x;
        if (i>0) curx = newloc(curx, jo[i-1]);
        for (int j=0;j<=m;j++){
            ii y;
            if (j>0) cury = newloc(cury, be[j-1]);
            if (i==0 && j==0)   continue;
            if (j>0 && i>0)    dp[i][j] = min(dp[i][j], dp[i-1][j-1] + dist(curx,cury));
            if (i>0)    dp[i][j] = min(dp[i][j], dp[i-1][j] + dist(curx,cury));
            if (j>0)    dp[i][j] = min(dp[i][j], dp[i][j-1] + dist(curx,cury));
        }
        cury = y1;
    }
    cout<<dp[n][m];
    return 0;
}

/*g++ -std=c++17 -O2 -Wall ".cpp" -o main.exe
./main.exe*/