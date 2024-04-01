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

struct Query{
    int l,r;
};

int n,S,q;
vector<Query> queries;
int a[N];
int pre[N],nxt[N];
unordered_map<int,int>  mp;

int ans;

int main(){
    setIO("");
    cin>>n>>q;
    pre[0]=INT_MIN;
    nxt[n-1]=inf;
    for (int i=0;i<n;i++){
        cin>>a[i];
        if (i==0)   {mp[a[0]]=0; continue;}
        pre[i]=(a[i] == a[mp[a[i]]]) ? mp[a[i]] : INT_MIN+1,   mp[a[i]]=i;
    }
    for (int i=n-2;i>=0;i--){
        nxt[i]=(mp[a[i]] != i) ? mp[a[i]] : inf-1,
        mp[ a[i] ] = i;
    }
//    for (int i=0;i<n;i++)   cout<<pre[i]<<' ';
//    cout<<'\n';
//    for (int i=0;i<n;i++)   cout<<nxt[i]<<' ';
//    cout<<'\n';
    for (int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        l--,r--;
        queries.pb({l,r});
    }
    S=sqrt(n);
    if (S<1) S=1;

    vector<int> queries_ids(q);
    vector<int> res(q);
    iota(queries_ids.begin(),queries_ids.end(),0);

    sort(queries_ids.begin(),queries_ids.end(), [&] (int q1, int q2){
            int bucket1 = queries[q1].l / S;
            int bucket2 = queries[q2].l / S;
            if (bucket1 != bucket2) return bucket1 < bucket2;
            else{
                return (bucket1%2)
                ? (queries[q1].r > queries[q2].r)
                : (queries[q1].r < queries[q2].r);
            }
         });
//    for (auto x:queries_ids)    cout<<x<< ' ';
//    cout<<'\n';

    int cur_l = -1, cur_r = -1;
    for (int qid : queries_ids) {
        // move to this range
        if (cur_l < 0) {
            for (int i = queries[qid].l; i <= queries[qid].r; ++i) {
                if (pre[i] < queries[qid].l)  ans++;
            }
            cur_l = queries[qid].l, cur_r = queries[qid].r;
        } else {
            while (cur_l > queries[qid].l)  {
                if (nxt[--cur_l] > cur_r)   ans++;
            }
            while (cur_r < queries[qid].r)  {
                if (pre[++cur_r] < cur_l)   ans++;
            }
            while (cur_r > queries[qid].r)  {
                if (pre[cur_r--] < cur_l)   ans--;
            }
            while (cur_l < queries[qid].l){
                if (nxt[cur_l++] > cur_r)   ans--;
            }
        }

        res[qid] = ans;
    }
    for (auto x:res)    cout<<x<<'\n';
    return 0;
}
