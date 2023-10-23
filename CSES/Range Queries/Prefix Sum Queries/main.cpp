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
const int N=2e5+5;

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

int n,q,S=1;
vt<pair<ll,ll>> seg;
ll a[N];

void build(){
    for (int i=S-1;i>0;i--){
        seg[i].fi = seg[i<<1].fi + seg[i<<1|1].fi;
        seg[i].se = max (seg[i<<1].fi + seg[(i<<1)|1].se, seg[i<<1].se);
    }
}

void update(int x,int val){
    seg[x+S].se = seg[x+S].fi = val;
    x=(x+S)>>1;
    for (x; x>=1; x/=2){
        seg[x].fi = seg[x<<1].fi + seg[x<<1|1].fi;
        seg[x].se = max (seg[x<<1].fi + seg[(x<<1)|1].se, seg[x<<1].se);
    }
}

ll max_pref (int l,int r){
    ll ans=0;
    ll sum1=0, pref=0, s=0, ss=0;
    for (l+=S,r+=S; l<=r; l/=2,r/=2){
        //debug(seg[l]);
        //debug(seg[r]);
        //debug(r);
        //debug(l);
        if (l&1)    {sum1 = max (s+seg[l].se, sum1);  s+=seg[l].fi; l++;}
        if (~r&1)   {pref = max (pref + seg[r].fi, seg[r].se); r--;}
        //debug(sum1);
        //debug(pref);
        //debug(s);
    }

    ans=max(sum1,s+pref);
    return ans;
}

int main(){
    setIO("t");
    cin>>n>>q;
    while (S<n) S*=2;
    seg.resize(S*2);
    for (int i=0;i<n;i++)   {cin>>a[i];     seg[i+S]={a[i],a[i]};}
    build();
    //cout<<seg[6]<<'\n';
    //cout<<seg[109]<<'\n';
    while (q--){
        int k,a,b;
        cin>>k>>a>>b;
        a--;
        if (k==1)   update(a,b);
        else {b--; cout<<max_pref(a,b)<<"\n";}
    }
}
