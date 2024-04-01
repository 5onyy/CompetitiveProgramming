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
const int N=2e5+5;
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

int n,q,mx,S=1;
int a[N];
vi co,seg;
unordered_map<int,int>  mp;

struct Query{
    char typ;
    int x;
    int y;
};

void update(int x,int val){
    for (x+=S;x>0;x/=2) seg[x] += val;
}

int get(int l,int r){
    int ans=0;
    for (l+=S,r+=S; l<=r; l/=2,r/=2){
        if (l%2)    ans+=seg[l++];
        if (r%2 == 0)   ans+=seg[r--];
    }
    return ans;
}

int main(){
    setIO("");
    cin>>n>>q;
    for (int i=0;i<n;i++){
        cin>>a[i];
        co.pb(a[i]);
    }
    vector<Query>   query;
    while (q--){
        char typ;   cin>>typ;
        int x,y;    cin>>x>>y;
        if (typ!='!') co.pb(x);
        co.pb(y);
        query.pb({typ,x,y});
    }
    rr(co);
    int m=co.size();
    while (S<m) S*=2;
    seg.resize(S*2);
    for (int w:co)  mp[w]=mx,   mx++;
    for (int i=0;i<n;i++)   a[i]=mp[a[i]];
    for (int i=0;i<n;i++)   update(a[i],1);
    for (int i=0;i<query.size();i++){
        int x=query[i].x;
        int y=query[i].y;
        //cout<<x<<' '<<y<<'\n';
        if (query[i].typ == '!'){
            update(a[x-1],-1);
            a[x-1]=mp[y];
            update(mp[y],+1);
        }
        else cout<<get(mp[x],mp[y])<<'\n';
    }
}
