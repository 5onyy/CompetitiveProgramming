/* http://usaco.org/index.php?page=viewproblem2&cpid=1018*/
#include<bits/stdc++.h>
#include<bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define sqr(x) ((x) * (x))
#define log2i(x) (64 - __builtin_clzll(1ll * (x)) - 1)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define debug(x)         {                                cout << #x << " = ";  cout << (x) << endl; }
#define rr(x) sort(all(x)), x.resize((unique(all(x)) - x.begin()));

template <typename T> using vt = vector<T>;
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

template <class U, class V> std::ostream &operator<<(std::ostream &out, const std::pair<U, V> &p) { return out << '(' << p.first << ", " << p.second << ')'; } // cout pair type

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

const ll mod = 1e9 + 7; // change to something else
struct Mod
{
    ll x;
    Mod(ll xx) : x(xx) {}
    Mod operator+(Mod b) { return Mod((x + b.x) % mod); }
    Mod operator-(Mod b) { return Mod((x - b.x + mod) % mod); }
    Mod operator*(Mod b) { return Mod((x * b.x) % mod); } /* */
    Mod operator^(ll e)
    {
        if (!e)
            return Mod(1);
        Mod r = *this ^ (e / 2);
        r = r * r;
        return e & 1 ? *this * r : r;
    }
};

template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
                  tree_order_statistics_node_update>;
Tree<pair<int,int>>   index_set;

int main()
{
    setIO("help");
    int n;
    cin >> n;
    vii seg(n);
    vt<Mod> dp(n+1,Mod(0));
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        seg[i] = {l, r};
    }
    sort(seg.begin(), seg.end());
    for (int i = 1; i <= n; i++){
        int l=seg[i-1].fi;
        int r=seg[i-1].se;
        ll cur = index_set.order_of_key({l,-1});
        dp[i] = dp[i-1];        //Part1:    the already calculated disjoint
        dp[i] = dp[i] + dp[i-1];
        Mod pwr = Mod(2)^cur; //Part2: the previous disjoint + the new segment (2^x mean the number of seg that seg[i] can't joint)
        dp[i] = dp[i] + pwr;
        index_set.insert({r,i-1});
    }
    cout<<dp[n].x;
}

/*g++ -std=c++17 -O2 -Wall ".cpp" -o main.exe
./main.exe*/
