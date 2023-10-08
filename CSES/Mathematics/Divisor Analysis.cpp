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

ll expo(ll x, ll y ,ll mod){
    ll ans=1;
    while (y){
        if (y&1)    ans = ans * x % mod;
        x = x * x % mod;
        y>>=1;
    }
    return ans;
}

const int N=1e6+5;
ll cnt[N],p[N];

const ll mod = 1e9+7;

int main(){
    setIO("");
    int n;
    cin>>n;
    ll sum=1, count=1, count2=1, product=1;
    for (int i=1;i<=n;i++)   cin>>p[i]>>cnt[i];
    for (int i=1;i<=n;i++){
        ll tmp =  ((expo(p[i],(cnt[i]+1),mod) - 1 ) * expo(p[i]-1,mod-2,mod))%mod;
        sum = (sum * tmp) % mod;        
        product = (expo(product,(cnt[i]+1),mod) * expo(expo(p[i],(cnt[i]*(cnt[i]+1)/2),mod),count2,mod))%mod;
        count = (count * (cnt[i]+1))%mod;
        count2 = (count2 * (cnt[i]+1)) % (mod-1);
    }
    std::cout<<count<<' '<<sum<<' '<<product<<'\n';
}

/* g++ -std=c++17 -O2 -Wall "Divisor Analysis.cpp" -o main.exe 
./main.exe */