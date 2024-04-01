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
const int d4i[4]= {-1, 0, 1, 0}, d4j[4]= {0, 1, 0, -1};
const int d8i[8]= {-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]= {0, 1, 1, 1, 0, -1, -1, -1};

template<class U, class V> std::ostream& operator << (std::ostream& out, const std::pair<U, V>& p) {
    return out << '(' << p.first << ", " << p.second << ')';   //cout pair type
}
template<typename T> using minpq = priority_queue<T, vt<T>,greater<T>>;
template<typename T> using maxpq = priority_queue<T>;

ll fgcd(ll a, ll b) {
    while(b) swap(b, a %= b);
    return a;
}
ll fpow(ll a, ll b, const ll c) {
    ll ans = 1;
    a %= c;
    for(; b; b >>= 1, a = a * a % c) if(b & 1) ans = ans * a % c;
    return ans;
}
ll fpow(ll a, ll b) {
    ll ans = 1;
    for(; b; b >>= 1, a *= a) if(b & 1) ans *= a;
    return ans;
}
int flog(int x) {
    return 31 - __builtin_clz(x);
}
int flog(ll x) {
    return 63 - __builtin_clzll(x);
}

void setIO(string name) {
    cin.tie(0)->sync_with_stdio(0);
    if(sz(name)) {
        freopen((name+".inp").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

const int N = 2e5 + 5;
int n,q,S;
vt<ll> seg_up,seg_down;
ll p[N];

void update(vt<ll> &seg, int x,ll val) {
    for (seg[x+=S] = val; x>1; x/=2 )   seg[x>>1] = min(seg[x],seg[x^1]);
}

ll query(vt<ll> &seg, int l,int r) {
    ll ans = INF;
    for (l+=S,r+=S; l<=r; l>>=1,r>>=1) {
        if (l&1)  ans = min(ans,seg[l++]);
        if (~r&1) ans = min(ans,seg[r--]);
    }
    return ans;
}

int main() {
    setIO("");
    cin>>n>>q;
    S=1;
    while (S<n) S*=2;
    seg_down.resize(2*S);
    seg_up.resize(2*S);
    for (int i=0; i<n; i++) {
        cin>>p[i];
        update(seg_up,i,p[i]+i); // p[j] + |k-j| -> p[j] + j - k
        update(seg_down,i,p[i]-i); // p[j] + |k-j| -> p[j] - j + k
    }
    while (q--) {
        int typ;
        cin>>typ;
        if (typ==1) {
            int k,x;
            cin>>k>>x;
            k--;
            p[k] = x;
            update(seg_up,k,p[k]+k);
            update(seg_down,k,p[k]-k);
        }
        else {
            int k;
            cin>>k;
            k--;
            cout<<min(query(seg_down,0,max(0,k-1))+k, query(seg_up,min(n-1,k),n-1)-k)<<'\n';
        }
    }
}
