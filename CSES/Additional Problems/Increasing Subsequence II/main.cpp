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
using ll = long long;
using ld = long double;
using vi = vt<int>;
using ii = pair<int, int>;
using vii = vt<ii>;

const ll INF=4e18;
const int inf=INT_MAX;
const int MOD=1e9+7;
const int N=2e5+5;
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

unordered_map<int,int> mp;
vi co;
int mx,S=1;
vi seg;
int a[N];

void update(int x,int val){
    for (x =(x+S); x>0 ;x/=2)  seg[x]=(seg[x]+val)%MOD;
}

ll get(int l,int r){
    ll ans=0;
    for (l+=S, r+=S; l<=r; l/=2, r/=2){
        if (l%2)    ans=(ans+seg[l++]) % MOD;
        if (r%2 == 0) ans=(ans+seg[r--]) % MOD;
    }
    return ans;
}

int main(){
    setIO("");
    int n;
    cin>>n;
    S=1;
    while (S<n) S*=2;
    seg.resize(2*S);
    for (int i=0;i<n;i++){
        cin>>a[i];
        co.pb(a[i]);    //coordinate compression
    }
    rr(co);
    for (int w:co)  mp[w]=mx,  mx++;
    for (int i=0;i<n;i++)   a[i]=mp[a[i]];
    //for (int i=0;i<n;i++)   cout<<a[i]<<' ';
    ll ans=0,num;
    for (int i=0;i<n;i++){
        num= 1 + get(0,a[i]-1);
        num%=MOD;
        //cout<<ans<<'\n';
        ans+=num;
        ans%=MOD;
        update(a[i],num);
    }
    cout<<ans;
}
