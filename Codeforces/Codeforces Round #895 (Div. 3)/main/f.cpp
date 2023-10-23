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

int n;

int main(){
    setIO("t");
    int test;
    cin>>test;
    while (test--){
        cin>>n;
        vi a(n+1,0);
        vi c(n+1,0);
        vi indeg(n+1,0);
        vi del(n+1,0);
        for (int i=1;i<=n;i++)  {
            cin>>a[i];  indeg[a[i]]++;
            // i-->a[i]
        }
        for (int i=1;i<=n;i++)  cin>>c[i];
        vi topo_sort;
        queue<int> q;
        for (int i=1;i<=n;i++){
            if (indeg[i] == 0)  q.push(i);
        }
        while (q.size()){
            int u=q.front();
            q.pop();
            indeg[a[u]]--;
            topo_sort.pb(u);
            del[u]=1;
            if (indeg[a[u]] == 0)   q.push(a[u]);
        }
        if ((int)topo_sort.size() == n){
            for (int u:topo_sort)   cout<<u<<' ';
            cout<<'\n';
        }
        else{
            int remaining=n-(int)topo_sort.size();
            //debug(remaining);
                for (int i=1;i<=n;i++){
                    if (del[i] == 0){
                        vi cycle;
                        int u=i;
                        int tmp=inf,ii=0;
                        while (!del[u]){
                            del[u]=1;
                            cycle.pb(u);
                            if (c[u] < tmp) {tmp=c[u];   if (del[a[u]]) ii=0; else ii=(int)cycle.size();}
                            u=a[u];
                        }
                        int cnt=cycle.size();
                        for (int j=0;j<cnt;j++)    topo_sort.pb((int)cycle[(j+ii)%cnt]);
                    }
                }
            for (int u:topo_sort)   cout<<u<<' ';
            cout<<'\n';
        }
    }
}

/* g++ -std=c++17 -O2 -Wall programName.cpp -o main.exe 
./main.exe */