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

const ll INF=4e18;
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

const int N = 1e5+5;
const int mod = 1e9+7;
int n,q;
ll a[N],pref[N];
pair<ll,ll> seg[4*N],lz[4*N];

void down(int id,int l,int r){
    int mid = (l + r)>>1;
    ll t1 = lz[id].fi;
    ll left_node = ( ((mid-l+1)*(mid+l))%mod * t1/2 )%mod;
    seg[id*2].fi = (seg[id*2].fi + left_node)%mod;
    ll right_node = ( ((r-mid)*(mid+1+r))%mod * t1/2 )%mod;
    seg[id*2+1].fi = (seg[id*2+1].fi + right_node)%mod;
    lz[id*2].fi = (lz[id*2].fi + t1)%mod;
    lz[id*2+1].fi = (lz[id*2+1].fi + t1)%mod;
    // first tree
    
    ll t2 = lz[id].se;
    seg[id*2].se = (seg[id*2].se + ((mid-l+1)*lz[id].se)%mod)%mod;
    seg[id*2+1].se = (seg[id*2+1].se + ((r-mid)*lz[id].se)%mod)%mod;
    lz[id*2].se = (lz[id*2].se + lz[id].se) % mod;
    lz[id*2+1].se = (lz[id*2+1].se + lz[id].se) % mod;
    //second tree;
    lz[id].fi = lz[id].se = 0LL;
}

void update(int id,int l,int r,int L,int R,int A,int B,int L2){
    if (L>r || R<l) return;
    if (L>=l && R<=r){
        ll left_node =(((R-L+1)*(L+R)%mod)*A/2)%mod; 
        seg[id].fi += left_node;  seg[id].fi %= mod;
        lz[id].fi += A; lz[id].fi %= mod;
        ll tmp = ((R-L+1)*(B-L2*A))%mod;
        seg[id].se += tmp;    seg[id].se %= mod;
        lz[id].se += (B-L2*A); lz[id].se %= mod; 
        return;
    }
    down(id,L,R);
    int mid = (L+R) >> 1;
    update(id*2,l,r,L,mid,A,B,L2);
    update(id*2+1,l,r,mid+1,R,A,B,L2);
    seg[id].fi = seg[id*2].fi + seg[id*2+1].fi;    seg[id].fi %= mod;
    seg[id].se = seg[id*2].se + seg[id*2+1].se;    seg[id].se %= mod;
}

pair<ll,ll> operator + (pair<ll,ll> a, pair<ll,ll> b){
    return {(a.fi+b.fi)%mod,(a.se+b.se)%mod};
}

pair<ll,ll> get(int id,int l,int r,int L,int R){
    if (L>r || R<l) return {0,0};
    if (L>=l && R<=r)   return {seg[id].fi,seg[id].se};
    down(id,L,R);
    int mid = (L+R)>>1;
    pair<ll,ll> le = get(id*2,l,r,L,mid); 
    pair<ll,ll> ri = get(id*2+1,l,r,mid+1,R);
    return le + ri;
}

int main(){
    setIO("");
    cin>>n>>q;
    while (q--){
        int typ;    cin>>typ;
        if (typ == 1){
            int L,R,A,B;   cin>>L>>R>>A>>B;
            update(1,L,R,1,n,A,B,L);
        }
        else{
            int l,r;    cin>>l>>r;
            pair<ll,ll> y = get(1,l,r,1,n);
            ll ans = (y.fi + y.se)%mod;
            cout<<ans<<"\n";
        }
    }
}
