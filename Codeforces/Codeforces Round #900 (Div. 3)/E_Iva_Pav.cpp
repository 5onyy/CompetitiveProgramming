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
const int N = 2e5+5;
int n;
int a[N];
int seg[4*N];

void build (int id, int l,int r){
    if (l==r){
        seg[id] = a[l];
        return;
    }
    int mid  = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    seg[id] = seg[id*2] & seg[id*2+1];
}

ll query(int id,int l,int r, int L,int R){
    if (L>r || R<l)     return INT_MAX;
    if (L>=l && R<=r)   return seg[id];
    int mid = (L+R) / 2;
    return query(id*2,l,r,L,mid) & query(id*2+1,l,r,mid+1,R);
}

int main(){
    setIO("");
    int test;
    cin>>test;
    while (test--){
        cin>>n;
        for (int i=1;i<=n;i++)   cin>>a[i];
        build(1,1,n);
        int q;
        cin>>q;
        while (q--)
        {
            int l,k;
            cin>>l>>k;
            int lo=l,hi=n,ans=-1;
            while (lo<=hi){
                int mid = (lo + hi)/2;
                if (query(1,l,mid,1,n) >= k)    ans = mid,  lo=mid+1;
                else hi = mid-1;
            }
            cout<<ans<<' ';
        }
        cout<<'\n';
        
    }
}
/*g++ -std=c++17 -O2 -Wall "E_Iva_Pav.cpp" -o main.exe 
./main.exe*/