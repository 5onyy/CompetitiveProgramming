#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef complex<ld> cp;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<cp> vcp;
typedef vector<ld> vld;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vii> vvii;

#define fastIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define forw(i,l,r) for( int i = (l) ; i < (r) ; i++ )
#define forb(i,r,l) for( int i = (r) ; i >= (l) ; i-- )
#define log2i(x) (32 - __builtin_clz((x)) - 1)
#define log2ll(x) (64 - __builtin_clzll((x)) - 1)
#define Pi 3.141592653589793
#define sz(x) (int)x.size()
#define mt make_tuple
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

const int N = 207;
const double inf = 1e14l;
int t,n;
bool kt=false;
double adj[N][N],dp[N];
bool vis[N];
ii points[N];
bool chk[N][N];

bool ReadLine() {
    string st; getline(cin,st);
    if(st=="") return false;
    stringstream stream(st);
    ii prev=mp(-1,-1);
    for(int x,y,i=n;stream >> x >> y,(x!=-1&&y!=-1);) {
        if(n!=i) chk[n][n-1]=chk[n-1][n]=true;
        prev=mp(x,y); points[n++]=prev;
    }
    return true;
}

int main() {
    fastIO;
    freopen("10389.inp","r",stdin);
    freopen("10389.out","w",stdout);

    cin >> t; cin.ignore();
    while(t--) {
        if(kt) cout << '\n';
        else kt=true;
        n=0; memset(chk,false,sizeof chk);
        forw(i,0,2) {
            int x,y; cin >> x >> y;
            points[n++]=mp(x,y);
        }
        cin.ignore();
        while(ReadLine());
        forw(i,0,n-1) forw(j,i+1,n) {
            ii x=points[i], y=points[j];
            double dis=hypot(1.0l*(x.fi-y.fi),1.0l*(x.se-y.se));
            if(!chk[i][j]) dis*=4;
            adj[i][j]=adj[j][i]=dis;
        }
        memset(vis,false,sizeof(bool)*n);
        forw(i,0,n) dp[i]=inf;
        dp[0]=0;
        forw(it,0,n) {
            int u=-1;
            forw(i,0,n) {
                if(!vis[i]&&(u==-1||dp[i]<dp[u])) u=i;
            }
            if(u==-1||dp[u]==inf) break;
            if(u==1) break;
            vis[u]=true;
            forw(i,0,n) {
                if(dp[u]+adj[u][i]<dp[i]) dp[i]=dp[u]+adj[u][i];
            }
        }
        cout << floor(dp[1]*3.0/2000.0+0.5) << '\n';
    }
    return 0;
}
