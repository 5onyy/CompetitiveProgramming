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
        freopen((name + ".inp").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}


ll euclid(ll a, ll b, ll &x, ll &y)
{
    if (!b)
        return x = 1, y = 0, a;
    ll d = euclid(b, a % b, y, x);
    return y -= a / b * x, d;
}


const ll mod = 1e9+7; // change to something else
struct Mod
{
    ll x;
    Mod() {};
    Mod(ll xx) : x(xx) {}
    Mod operator+(Mod b) { return Mod((x + b.x) % mod); }
    Mod operator-(Mod b) { return Mod((x - b.x + mod) % mod); }
    Mod operator*(Mod b) { return Mod((x * b.x) % mod); }
    Mod operator/(Mod b) { return *this * invert(b); }
    Mod invert(Mod a)
    {
        ll x, y, g = euclid(a.x, mod, x, y);
        assert(g == 1);
        return Mod((x + mod) % mod);
    }
    Mod operator^(ll e)
    {
        if (!e)
            return Mod(1);
        Mod r = *this ^ (e / 2);
        r = r * r;
        return e & 1 ? *this * r : r;
    }
};

const int N=2e5+5;
int n,m,k;
Mod fact[N];

int main()
{
    setIO("t");
    int test;
    cin >> test;
    fact[0] = Mod(1);
    for (int i=1;i<N;i++)  fact[i] = fact[i-1] * Mod(i);
    auto biom = [] (int n,int k){
        if (k>n)    return (Mod(0));
        Mod ans = fact[n] / fact[k] / fact[n-k];
        return ans;
    };
    //debug(biom(2,3).x);
    while (test--)
    {
        cin >> n >> m >> k;
        vi freq(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            freq[x]++;
        }
        vi prefreq(n+1,0);
        Mod ans(0);
        for (int i=1;i<=n;i++)  prefreq[i] = freq[i] + prefreq[i-1];
        for (int i=1;i<=n;i++){
            int max_idx = min(i + k , n);
            ll num_element = prefreq[max_idx] - prefreq[i-1];
            ll num_upperbound = prefreq[max_idx] - prefreq[i];
            //debug(num_element);
            //debug(num_upperbound);
            Mod cur = biom(num_element, m) - biom(num_upperbound,m);
            //debug(cur.x);
            ans = ans + cur;
        }
        cout<<ans.x<<'\n';
    }
}

/*g++ -std=c++17 -O2 -Wall ".cpp" -o main.exe
./main.exe*/