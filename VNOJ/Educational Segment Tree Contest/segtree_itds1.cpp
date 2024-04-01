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

const int N = 1e5 + 5;

int a[N],n,S;
multiset<int> seg[4*N];

void build(int id,int l,int r){
    if (l==r){
        seg[id].insert(a[l]);   return;
    }
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    seg[id].insert(seg[id*2].begin(),seg[id*2].end());
    seg[id].insert(seg[id*2+1].begin(),seg[id*2+1].end());
}

void update(int id,int l,int r,int x,int val,int old){
    if (l==r){
        if (l==x){
            seg[id].erase(old);    seg[id].insert(val);
            for (int tmp = id ; tmp > 1 ; tmp/=2)    {
                seg[tmp>>1].erase(seg[tmp>>1].find(old)); 
                seg[tmp>>1].insert(val);
            }
        }  
        return;
    }
    int mid = (l+r)/2;
    if (x<=mid) update(id*2,l,mid,x,val,old);
    else update(id*2+1,mid+1,r,x,val,old);
}

int query(int id,int l,int r,int L,int R,int k){
    if (L>r || R<l) return inf;
    if (L>=l && R<=r){
        if (seg[id].lower_bound(k) == seg[id].end())    return inf;
        return *seg[id].lower_bound(k);
    }
    int mid = (L+R) >> 1;
    return min(query(id*2,l,r,L,mid,k),query(id*2+1,l,r,mid+1,R,k));
}

int main(){
    setIO("");
    int q;
    cin>>n>>q;
    for (int i=1;i<=n;i++)  cin>>a[i];
    build(1,1,n);
    while (q--){
        int typ;    cin>>typ;
        if (typ == 1){
            int x,val;  cin>>x>>val;
            update(1,1,n,x,val,a[x]);
            a[x] = val;
            //for (auto &itr: seg[1])     cout<<itr<<' ';
            //cout<<'\n';
        }
        else{
            int l,r,k;  cin>>l>>r>>k;
            int ans = query(1,l,r,1,n,k);
            if (ans==inf)   cout<<-1<<'\n';
            else cout<<ans<<"\n";
        }
    }

}
