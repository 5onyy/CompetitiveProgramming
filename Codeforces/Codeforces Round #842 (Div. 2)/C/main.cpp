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
#define int long long
#define double long double
#define log2(x)        log(x)/log(2.0)
#define hardio(x)      freopen(x".inp","r",stdin), freopen(x".out","w",stdout);
#define rall(x)        x.rbegin(),x.rend()

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int maxN=1001;
const int BASE=311;
const int N=1e5+5;
const int MOD=1000000003;
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

int d[200001];

void solve()
{
    int n,mm=0;
    cin>>n;
    memset(d,0,sizeof d);
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        d[a[i]]+=1;
        if (d[a[i]>2)
        {
            cout<<"NO"<<endl;
            return;
        }
        mm=max(mm,a[i]);
        s.insert(i);
    }

    if (n==1)
    {
        cout<<"YES"<<endl;
        cout<<1<<endl;
        cout<<1<<endl;
        return;
    }
    if (mm<n)
    {
        cout<<"NO"<<endl;
        return;
    }
    for (int i=1;i<=n;i++)
    {
        if (d[a[i]]==2)
        {
            res1[i]=a[i];   d[a[i]]--;
        }
    }
}

signed main()
{
    fastIO;
    int tests;
    cin>>tests;
    while (tests--)
    {
        solve();
    }
}
