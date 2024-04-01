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
#define rep(i, a, b) for (int i = a; i < (b); ++i)

template<typename T> using vt = vector<T>;
using ll = long long;
using ld = long double;
using vi = vt<int>;
using ii = pair<int, int>;
using vii = vt<ii>;

const ll INF = 4e18;
const int inf = INT_MAX;
const int MOD = 1000000003;
const int d4i[4] = { -1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
const int d8i[8] = { -1, -1, 0, 1, 1, 1, 0, -1}, d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};

template<class U, class V> std::ostream& operator << (std::ostream& out, const std::pair<U, V>& p) {return out << '(' << p.first << ", " << p.second << ')';}   //cout pair type
template<typename T> using minpq = priority_queue<T, vt<T>, greater<T>>;
template<typename T> using maxpq = priority_queue<T>;

ll fgcd(ll a, ll b) {while (b) swap(b, a %= b); return a;}
ll fpow(ll a, ll b, const ll c) { ll ans = 1; a %= c; for (; b; b >>= 1, a = a * a % c) if (b & 1) ans = ans * a % c; return ans;}
ll fpow(ll a, ll b) {ll ans = 1; for (; b; b >>= 1, a *= a) if (b & 1) ans *= a; return ans;}
int flog(int x) {return 31 - __builtin_clz(x);}
int flog(ll x) {return 63 - __builtin_clzll(x);}

void setIO(string name) {
	cin.tie(0)->sync_with_stdio(0);
	if (sz(name)) {
		freopen((name + ".inp").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int n, q, S, timer;
vi st, en;
vt<vi> a;

void dfs(int u, int par = -1) {
	st[u] = timer++;
	for (int v : a[u])
		if (v != par)	dfs(v, u);
	en[u] = timer;
}

int main() {
	setIO("");
	cin >> n >> q;
	a.resize(n, vi());	st.resize(n);	en.resize(n);
	vi vals(n);
	for (auto &x : vals)	cin >> x;
	for (int i = 0; i < n; i++) {
		int u, v;	cin >> u >> v;	u--;	v--;
		a[u].pb(v);	a[v].pb(u);
	}

	S = 1;
	while (S < n)	S *= 2;
	vi seg(2 * S);
	auto update = [] (int x, int val) {
		for (seg[x += S] = val; 	x > 0; x /= 2)
			seg[x >> 1] = max(seg[x], seg[x ^ 1]);
	}
	auto query = [] (int l, , int r) {
		int ans = INT_MAX;
		for (l += S, r += S, l <= r; l++, r--) {
			if (l & 1)	ans = max(ans, seg[l--]);
			if (~r & 1)	ans = max(ans, seg[r--]);
		}
	}
	while (q--) {
		int typ;
	}
}