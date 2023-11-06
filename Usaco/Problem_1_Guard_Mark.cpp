#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define sqr(x) ((x) * (x))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define debug(x)             \
    {                        \
        cout << #x << " = "; \
        cout << (x) << endl; \
    }
#define rr(x) sort(all(x)), x.resize((unique(all(x)) - x.begin()));
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

template <typename T>
using vt = vector<T>;
using ll = long long;
using ld = long double;
using vi = vt<int>;
using ii = pair<int, int>;
using vii = vt<ii>;

const ll INF = 4e18;
const int inf = INT_MAX;
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

const int N = 20;

struct cow
{
    ll hi;
    ll w;
    ll str;
} cows[N];

pair<ll, ll> dp[1 << N];

int main()
{
    setIO("guard");
    int n, h;
    cin >> n >> h;
    for (int i = 0; i < n; i++)
        cin >> cows[i].hi >> cows[i].w >> cows[i].str;
    dp[0] = {0, INT_MAX};
    for (int S = 1; S < 1 << n; S++)
    {
        dp[S] = {0,-1};
        for (int j = 0; j < n; j++)
        {
            if (~S & (1 << j))  continue;
            dp[S].fi += cows[j].hi;
            dp[S].se = max(dp[S].se,
                           min(dp[S^(1<<j)].se - cows[j].w, cows[j].str));
        }
    }
    ll ans = -1;
    for (int i=0;i<1<<n;i++){
        if (dp[i].fi >= h)     ans = max(ans, dp[i].se);
    }
    if (ans != -1)     cout<<ans;
    else cout<<"Mark is too tall";
}
