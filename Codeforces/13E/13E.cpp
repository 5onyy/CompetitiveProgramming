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
const int N=1e5+5;

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


vi pwr;
int S,n,q;


struct node{
    int nxt,cnt,last;
    node(): nxt(0), cnt(0), last(0) {};
    node (int _nxt, int _cnt, int _last) : nxt(_nxt), cnt(_cnt), last(_last) {};
};

node res[N];


void update(int cur){
    int blk=cur/S;
    int to=cur+pwr[cur];
    if (to / S > blk || to>=n)   res[cur]=node( cur+pwr[cur] ,1, cur);
    else res[cur]= node( res[to].nxt, res[to].cnt+1, res[to].last);
}

int main(){
    setIO("t");
    cin>>n>>q;
    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        pwr.pb(x);
    }
    S=sqrt(n);
    if (S<1)    S=1;
    for (int i=n-1;i>=0;i--){
        update(i);
    }
//    for (int i=0;i<n;i++) cout<<res[i].last<<' ';
//    cout<<'\n';
//    for (int i=0;i<n;i++) cout<<res[i].nxt<<' ';
//    cout<<'\n';
//    for (int i=0;i<n;i++) cout<<res[i].cnt<<' ';
//    cout<<'\n';
    while (q--){
        int typ;
        cin>>typ;
        if (!typ){
            int u,tmp;
            cin>>u>>tmp;
            u--;
            int blk=u/S;
            pwr[u]=tmp;
            for (u; u>=blk*S;u--)   update(u);
        }
        else{
            int ind,lst,ans=0;
            cin>>ind;
            ind--;
            lst=ind;
            while (ind < n){
                lst=res[ind].last;
                ans+=res[ind].cnt;
                ind=res[ind].nxt;
            }
            cout<<lst+1<<' '<<ans<<'\n';
        }
    }
}
