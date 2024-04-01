#include<bits/stdc++.h>
#include<tr1/unordered_map>

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
const int S=sqrt(N);

template<class U, class V> std::ostream& operator << (std::ostream& out, const std::pair<U, V>& p) {return out << '(' << p.first << ", " << p.second << ')';}   //cout pair type
template<typename T> using minpq = priority_queue<T, vt<T>,greater<T>>;
template<typename T> using maxpq = priority_queue<T>;

ll fgcd(ll a, ll b) {while(b) swap(b, a %= b); return a;}
ll fpow(ll a, ll b, const ll c) { ll ans = 1; a %= c; for(; b; b >>= 1, a = a * a % c) if(b & 1) ans = ans * a % c; return ans;}
ll fpow(ll a, ll b) {ll ans = 1; for(; b; b >>= 1, a *= a) if(b & 1) ans *= a; return ans;}
int flog(int x) {return 31 - __builtin_clz(x);}
int flog(ll x) {return 63 - __builtin_clzll(x);}

void setIO(string name) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if(sz(name)) {
        freopen((name+".inp").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

struct Query{
    ll l,r;
};


ll n,q,k;
vector<Query> mo;
ll a[N],pref[N];
tr1::unordered_map <ll,ll> cnt;

void solve(){
    cin>>q;
    for (int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        mo.pb({l,r});
    }
    vt<ll> ids(q);
    iota(ids.begin(),ids.end(),0);
    sort(ids.begin(),ids.end(), [&] (int q1,int q2){
            int bucket1=mo[q1].l / S;
            int bucket2=mo[q2].l / S;
            if (bucket1 != bucket2) return bucket1 < bucket2;
            else{
                if (bucket1&1)  return mo[q1].r>mo[q2].r;
                return mo[q1].r < mo[q2].r;
            }
        });
//    for (int qid : ids) cout<<mo[qid].l<<' '<<mo[qid].r<<'\n';
//    cout<<'\n';
    cnt[0]=1;
    ll cur_l=1,cur_r=0;
    ll ans=0;
    vt<ll> res(q);
    for (ll qid : ids){
        while (cur_l > mo[qid].l){
            cur_l--;
            ans += cnt[pref[cur_l-1]+k];
            cnt[pref[cur_l-1]]++;
        }
        while (cur_r < mo[qid].r){
            cur_r++;
            ans+=cnt[pref[cur_r]-k];
            cnt[pref[cur_r]]++;
        }
        while (cur_r > mo[qid].r){
            cnt[pref[cur_r]]--;
            ans-=cnt[pref[cur_r]-k];
            cur_r--;
        }
        while (cur_l < mo[qid].l){
            cnt[pref[cur_l-1]]--;
            ans -= cnt[pref[cur_l-1]+k];
            cur_l++;
        }
        res[qid]=ans;
    }
    for (auto xs : res){
        cout << xs << '\n';
    }
}

int main(){
    setIO("t");
    cin>>n>>k;
    for (int i=0;i<n;i++){
        cin>>a[i];
        a[i] = (a[i]==1) ? 1 : -1;
    }
    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i]*=x;
        pref[i+1]= pref[i]+a[i];
    }
    solve();
}

