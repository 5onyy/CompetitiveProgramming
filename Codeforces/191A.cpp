#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define sqr(x) ((x) * (x))
#define all(x)         x.begin(),x.end()
#define rr(x)          sort(all(x)),x.resize((unique(all(x))-x.begin()));
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define timer cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"

template<typename T> using vt = vector<T>;
using ll = long long;
using ld = long double;
using vi = vt<int>;
using ii = pair<int, int>;
using iii = pair<int, ii>;
using vii = vt<ii>;

const ll INF = 4e18;
const int inf = INT_MAX;
const int td[8] = { -1, 0, 1, 0, -1, -1, 1, 1}, tc[8] = {0, 1, 0, -1, -1, 1, 1, -1};
template<typename T> using minpq = priority_queue<T, vt<T>, greater<T>>;
template<typename T> using maxpq = priority_queue<T>;

/*-------------------------------FOR DEBUGGING --------------------------------------*/
#define DEBUG(X) { auto _X = (X); std::cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << std::endl; }
#define db(x) { std::cerr << "[" << #x << " = "; std::cerr << (x) << "] "; }
#define debug(x) { std::cerr << "[" << #x << " = "; std::cerr << (x) << "] " << endl; }

// For printing std::pair, container, etc.
template<class U, class V> std::ostream& operator << (std::ostream& out, const std::pair<U, V>& p) {
	return out << '(' << p.first << ", " << p.second << ')';
}

template<class Con, class = decltype(begin(std::declval<Con>()))>
typename std::enable_if < !std::is_same<Con, std::string>::value, std::ostream& >::type
operator << (std::ostream& out, const Con& con) {
	out << '{';
	for (auto beg = con.begin(), it = beg; it != con.end(); it++) {
		out << (it == beg ? "" : ", ") << *it;
	}
	return out << '}';
}
template<size_t i, class T> std::ostream& print_tuple_utils(std::ostream& out, const T& tup) {
	if (i == std::tuple_size<T>::value) return out << ")";
	else return print_tuple_utils < i + 1, T > (out << (i ? ", " : "(") << get<i>(tup), tup);
}
template<class ...U> std::ostream& operator << (std::ostream& out, const std::tuple<U...>& t) {
	return print_tuple_utils<0, std::tuple<U...>>(out, t);
}
/*-----------------------------------------------------------------------------------*/

ll fgcd(ll a, ll b) {while (b) swap(b, a %= b); return a;}
ll fpow(ll a, ll b, const ll c) { ll ans = 1; a %= c; for (; b; b >>= 1, a = a * a % c) if (b & 1) ans = ans * a % c; return ans;}
ll fpow(ll a, ll b) {ll ans = 1; for (; b; b >>= 1, a *= a) if (b & 1) ans *= a; return ans;}
int flog(ll x) {return 63 - __builtin_clzll(x);}    //for integer : 31 - __builin_clz(x);

void setIO(string name) {
	cin.tie(0)->sync_with_stdio(0);
	if (sz(name)) {
		freopen((name + ".inp").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
const int N = 5e5 + 5;
int dp[30][30];
int n;
int cnt_l[30], cnt_r[30];

int32_t main() {
	setIO("");
	cin >> n;
	vt<string> a(n);
	int ans = 0;
	for (auto &x : a) {
		cin >> x;
	}
	for (int  i = 0; i < n; i++) {
		int l = a[i][0] - (int)'a';
		int r = a[i][sz(a[i]) - 1] - 'a';
		for (int j = 0; j < 26; j++) {	//FOR EACH START LETTER
			if (dp[j][l])
				dp[j][r] = max(dp[j][r], dp[j][l] + sz(a[i]));
		}
		dp[l][r] = max(dp[l][r], sz(a[i]));
	}
	for (int i = 0; i < 30; i++)
		if (dp[i][i] != 0) {
			//db(i);	db(dp[i][i]);
			ans = max(ans, dp[i][i]);
		}
	cout << ans;
	timer;
}