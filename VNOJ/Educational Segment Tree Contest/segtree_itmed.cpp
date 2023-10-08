#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define sqr(x) ((x) * (x))
#define all(x)         x.begin(),x.end()
#define rall(x)        x.rbegin(),x.rend()
#define debug(x) { cout << #x << " = "; cout << (x) << endl; }
#define rr(x)          sort(all(x)),x.resize((unique(all(x))-x.begin()));
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

template<typename T> using vt = vector<T>;
using ll = long long;
using ld = long double;
using vi = vt<int>;
using ii = pair<int, int>;
using vii = vt<ii>;

const ll INF=4e14;
const int inf=INT_MAX;
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

const int N = 1e6 + 5;
int n,k,S=1;
ll a[N];
vt<ll> seg;

void update(int x,ll val){
    seg[x+S] = val;
    for (x+=S;x>1;x>>=1)    seg[x>>1] = max (seg[x],seg[x^1]);
}

ll query(int l,int r){
    ll ans = -INF;
    for (l+=S,r+=S;l<=r;l/=2,r/=2){
        if (l&1) ans = max(ans,seg[l++]);   
        if (~r&1)  ans = max (ans,seg[r--]);
    }
    return ans;
}

int main(){
    setIO("");
    cin>>n>>k;
    while (S<n) S*=2;
    seg.resize(2*S);
    for (int i=0;i<n;i++)  {cin>>a[i];  update(i,a[i]);}
    vt<ll> dp(n,-INF);
    ll ans = -INF;
    for (int i=n-1;i>=0;i--){
        int l = min(n-1,i+1);
        int r = min(n-1,i+k);
        dp[i] = max(0LL,query(l,r))+a[i];
        if (i==n-1) dp[i] = a[i];
        ans = max (ans,dp[i]);
        update(i,dp[i]);
    }
    cout<<max(ans,0LL)<<'\n';
}