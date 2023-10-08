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

int n;
vi bit, a, lz;
vt<vi> seg;

void build(int id, int l, int r)
{
    if (l == r)
    {
        seg[id][bit[l]] = a[l];
        seg[id][bit[l] ^ 1] = 0;
        lz[id]=0;
        return;
    }
    int mid = (l + r) >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    lz[id]=0;
    seg[id][0] = seg[id * 2][0] ^ seg[id * 2 + 1][0];
    seg[id][1] = seg[id * 2][1] ^ seg[id * 2 + 1][1];
}

void update(int id, int l, int r, int L, int R)
{
    if (L > r || R < l)
        return;
    if (L >= l && R <= r)
    {
        swap(seg[id][0],seg[id][1]);
        lz[id]^=1;
        return;
    }
    if (lz[id] != 0)
    {
        lz[id<<1] ^= 1;
        lz[id<<1|1] ^= 1;
        swap(seg[id << 1][0], seg[id<<1][1]);
        swap(seg[id << 1|1][0], seg[id<<1|1][1]);
        lz[id] = 0;
    }
    int mid = (L + R) >> 1;
    update(id << 1, l, r, L, mid);
    update(id << 1 | 1, l, r, mid + 1, R);
    seg[id][0] = seg[id * 2][0] ^ seg[id * 2 + 1][0];
    seg[id][1] = seg[id * 2][1] ^ seg[id * 2 + 1][1];
}

int main()
{
    setIO("t");
    int test;
    cin >> test;
    while (test--)
    {
        cin >> n;
        a.assign(n + 1,0);
        seg.assign(4 * (n + 1), vi(2, 0));
        lz.assign(4 * (n * +1), 0);     //lz : save the changing state signal (1: need inverse, 0: none)
        for (int i = 1; i <= n; i++)            cin >> a[i];
        string s;
        cin >> s;
        bit.assign(s.size() + 1, 0);
        for (int i = 0; i < (int)s.size(); i++)
            bit[i + 1] = (int)s[i] - (int)'0';
        build(1, 1, n);
        //debug(seg[3][0]);
        //debug(seg[3][1]);
        int q;
        cin >> q;
        while (q--)
        {
            int typ, l, r;
            cin >> typ;
            if (typ == 2)
            {
                cin >> l;
                cout << seg[1][l] << ' ';
            }
            else
            {
                cin >> l >> r;
                update(1, l, r, 1, n);
            }
        }
        cout<<'\n';
    }
}

/* g++ -std=c++17 -O2 -Wall programName.cpp -o main.exe
./main.exe */