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

int n,t,S;
ll sum;
vi a;
int ap[1000001];

struct query{
    int l,r,id;
};

bool cmp (const query &A, const query &B){
    int bucket1 = A.l / S;
    int bucket2 = B.l / S;
    if (bucket1 != bucket2)  return bucket1 < bucket2;
    return A.r < B.r;
}

void add(int x){
    sum+= (2*x*ap[x] + x);
    ap[x]++;
}

void del(int x){
    sum-= (2*x*ap[x] - x);
    ap[x]--;
}

int main(){
    setIO("t");
    cin>>n>>t;
    S=sqrt(n);
    if (S<1) S=1;
    vector<query> mo(t);
    for (int i=0;i<n;i++) {int x;   cin>>x;  a.pb(x);}
    for (int i=0;i<t;i++){
        int _l,_r;
        cin>>_l>>_r;
        mo[i].l=--_l;
        mo[i].r=--_r;
        mo[i].id=i;
    }
    sort(mo.begin(),mo.end(),cmp);
    //for (auto [l,r,id] : mo)    cout<<l<<' '<<r<<' '<<id<<'\n';
    vector<ll> res(t);
    int cur_l=-1,cur_r=-1;
    for (int i=0;i<t;i++){
        if (cur_l<0){
            for (int j=mo[i].l;j<=mo[i].r;j++)  add(a[j]);
            cur_l=mo[i].l,  cur_r=mo[i].r;
        }
        else{
            while (cur_l < mo[i].l) del(a[cur_l++]);
            while (cur_r < mo[i].r) add(a[++cur_r]);
            while (cur_l > mo[i].l) add(a[--cur_l]);
            while (cur_r > mo[i].r) del(a[cur_r--]);
        }
        res[mo[i].id]=sum;
        //cout<<sum<<'\n';
    }
    for (int i=0;i<t;i++)   cout<<res[i]<<'\n';
    return 0;
}
