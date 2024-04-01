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

int a[maxN][maxN],p[maxN][maxN];
int n,q;

int rec(int x1,int y1,int x2,int y2)
{
    return p[x2][y2]-p[x2][y1-1]-p[x1-1][y2]+p[x1-1][y1-1];
}

signed main()
{
    //hardio("t");
    fastIO;
    cin>>n>>q;
    for (int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for (int j=0;j<sz(s);j++)
        {
            if (s[j]=='*')
                p[i][j+1]=1;
        }
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            p[i][j]+=p[i][j-1]+p[i-1][j]-p[i-1][j-1];
//    for (int i=1;i<=n;i++)
//    {
//        for (int j=1;j<=n;j++)
//            cout<<a[i][j]<<" ";
//        cout<<endl;
//    }
//    cout<<endl;
//    for (int i=1;i<=n;i++)
//    {
//        for (int j=1;j<=n;j++)
//            cout<<p[i][j]<<" ";
//        cout<<endl;
//    }
//    cout<<endl;

    while (q--)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<rec(x1,y1,x2,y2)<<endl;
    }
}
