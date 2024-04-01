#include<bits/stdc++.h>

using namespace std;

#define fastIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mp make_pair
#define inf 999999999
#define sz(x) (int)(x).size()
#define log2i(x) (64 - __builtin_clzll(1ll * (x)) - 1)
#define hardio(x)      freopen(x".inp","r",stdin), freopen(x".out","w",stdout);
#define all(x)         x.begin(),x.end()
#define rall(x)        x.rbegin(),x.rend()
#define int long long

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;

const int maxN=1001;
const int BASE=311;
const int N=1e5+5;
const int MOD=1000000003;
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

int n;


signed main()
{
    //hardio("t");
    fastIO;
    cin>>n;
    vi v(n);
    for (int i=0;i<n;i++)
        cin>>v[i];
    sort(all(v));
    int cur=1,sum=0;
    for (int i=0;i<n;i++)
    {
        if (cur < v[i])
        {
            cout<<cur;  exit(0);
        }
        if (cur>=v[i])
        {
            sum+=v[i];
            cur=sum+1;
        }
    }
    cout<<cur;
}
