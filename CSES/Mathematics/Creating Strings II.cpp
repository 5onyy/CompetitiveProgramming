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
using ll = unsigned long long;
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
        freopen((name+".inp").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

const ll N=1e6+5;

ll fact[N+1], inv [N+1];
ll cnt[100];
const ll mod = 1000000007, LIM = 1000002;

ll expo (ll x, ll e, ll mod){
        if (!e) return 1LL;
        ll r = expo(x, e/2 , mod); r = r * r % mod;
        return e&1 ? (r * x) % mod : r;
    };

int main(){
    setIO("");
    string s;
    cin>>s;
    int n=s.size();
    //debug(expo(3,4,mod));
    for (int i=0;i<(int)s.size();i++)    cnt[s[i]-'a']++;
    fact[0]=1;
    for (ll i=1;i<=N;i++)  fact[i] = fact[i-1] * i % mod;
    inv [N] = expo(fact[N],mod-2,mod);
    inv[0]=1;
    for (ll i = N-1 ; i>0 ; i--)   inv[i] = (i+1) * inv[i+1] % mod;

    int cur=n;
    ll ans = fact[n];
    for (int i = 0; i<=90 ;i++){
        if (cnt[i]!=0){
            ans = ans * inv[cnt[i]] % mod;
            cur-=cnt[i];
        }
    }
    cout<<ans;
}

/* g++ -std=c++17 -O2 -Wall "Creating Strings II.cpp" -o main.exe
./main.exe */
