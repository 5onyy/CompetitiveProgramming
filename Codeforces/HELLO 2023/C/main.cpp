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
#define log2(x)        log(x)/log(2.0)
#define hardio(x)      freopen(x".inp","r",stdin), freopen(x".out","w",stdout);
#define rall(x)        x.rbegin(),x.rend()

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;

const int maxN=1001;
const int BASE=311;
const int N=1e5+5;
const int MOD=1000000003;
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

int n,m;

void solve()
{
    cin>>n>>m;
    vi a(n);
    ll sum=0,ans=0;
    for (int i=0;i<n;i++)
        cin>>a[i];
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i=m;i<n;i++)
    {
        sum+=a[i];
        pq.push(a[i]);
        while (sum<0)
        {
            sum+=2*(-pq.top());
            ans++;
            pq.push(-pq.top());
            pq.pop();
        }
    }
    priority_queue<ll> pq2;
    sum=0;
    for (int i=m-1;i>0;i--)
    {
        sum+=a[i];
        pq2.push(a[i]);
        while (sum>0)
        {
            sum-=2*pq2.top();
            ans++;
            pq2.push(-pq2.top());
            pq2.pop();
        }
    }
    cout<<ans<<endl;
}

int main()
{
    fastIO;
    int tests;
    cin>>tests;
    while (tests--)
    {
        solve();
    }
}

