// update node u to x <-> all sum in the path from 1 to subtree of u increase by x - vals[u]. use fenwick to calculate the sum from 0 to u
// update: all element in range [u,v] increase by k <-> f[u] += k;	f[v] -= k
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

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a [ pos ] += d i f
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0 , pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos - 1];
		return res;
	}
	int lower_bound(ll sum) {// min pos s t sum of [0 , pos ] >= sum
		// Returns n i f no sum is >= sum, or −1 i f empty sum is .
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw - 1] < sum)
				pos += pw, sum -= s[pos - 1];
		}
		return pos;
	}
};

int n, q, timer;
vt<vi> a;
vi start, en;

void euler_tour(int u, int par = -1) {
	start[u] = timer++;
	for (int v : a[u])
		if ( v != par)	euler_tour(v, u);
	en[u] = timer - 1;
}

int main() {
	setIO("");
	cin >> n >> q;
	a.resize(n, vi());
	start.resize(n);	en.resize(n);
	vi vals(n);
	FT bit(n);
	for (auto &x : vals) cin >> x;
	for (int i = 0; i < n - 1; i++) {
		int u, v;	cin >> u >> v;	u--;	v--;
		a[u].pb(v);	a[v].pb(u);
	}
	euler_tour(0);
	for (int i = 0; i < n; i++) {
		bit.update(start[i], vals[i]);
		bit.update(en[i] + 1, -vals[i]);
	}
	while (q--) {
		int typ;	cin >> typ;
		if (typ == 1) {
			int s, x;	cin >> s >> x;	s--;
			bit.update(start[s], x - vals[s]);
			bit.update(en[s] + 1, - (x - vals[s]));
			vals[s] = x;
		}
		else {
			int s;	cin >> s;	s--;
			cout << bit.query(start[s] + 1) << '\n';
		}
	}
}