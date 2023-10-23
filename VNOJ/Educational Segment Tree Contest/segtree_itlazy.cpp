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

const int N = 1e5 +5;

int n,q;
ll a[N];
ll seg[N*4],lz[4*N];

void down(int id){
    seg[id*2+1] += lz[id];
    seg[id*2] += lz[id];
    lz[id*2+1] += lz[id];
    lz[id*2] += lz[id];
    lz[id] = 0;
    return;
}

void update (int id,int L,int R,int l,int r,int val){
    if (L>r || R<l) return;
    if (L>=l && R<=r){
        seg[id] += val;
        lz[id] += val;
        return;
    }
    int mid = (L+R)/2;
    down(id);
    update(id*2,L,mid,l,r,val);
    update(id*2+1,mid+1,R,l,r,val);
    seg[id] = max(seg[id*2],seg[id*2+1]);
}

ll query(int id,int L,int R,int l,int r){
    if (L>r || R<l) return -INF;
    if (L>=l && R<=r){
        return seg[id];
    }
    int mid = (R+L)/2;
    down(id);
    return max (query(id*2,L,mid,l,r),query(id*2+1,mid+1,R,l,r));
}

int main(){
    setIO("");
    cin>>n;
    for (int i=1;i<=n;i++)  {cin>>a[i]; update(1,1,n,i,i,a[i]);}
    //cout<<query(1,1,n,1,n);
    cin>>q;
    while (q--){
        int typ;    cin>>typ;
        if (typ == 1){
            int l,r,k;  cin>>l>>r>>k;   
            update(1,1,n,l,r,k);
        }
        else{
            int l,r;    cin>>l>>r;
            cout<<query(1,1,n,l,r)<<'\n';
        }
    }
}
