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

void solve(int n)
{
    if ((n*(n+1)/2)%2 != 0)
    {
        cout<<"NO";
        return;
    }
    cout<<"YES"<<endl;
    if (n%2==0)
    {
        cout<<n/2<<endl;
        for (int i=1;i<=n/2;i+=2)
            cout<<i<<" "<<n-i+1<<" ";
        cout<<endl;
        cout<<n/2<<endl;
        for (int i=2;i<=n/2;i+=2)
            cout<<i<<" "<<n-i+1<<" ";
        return;
    }
    cout<<n/2+1<<endl;
    cout<<1<<" "<<n-1<<" ";
    for (int i=2;i<n/2;i+=2)
        cout<<i<<" "<<n-i<<" ";
    cout<<endl;
    cout<<n/2<<endl;
    cout<<n<<" ";
    for (int i=3;i<=n/2;i+=2)
        cout<<i<<" "<<n-i<<" ";
}

signed main()
{
    //hardio("t");
    fastIO;
    cin>>n;
    solve(n);

}
