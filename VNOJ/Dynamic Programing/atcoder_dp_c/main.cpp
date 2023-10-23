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
const int MOD=1000000003;
const int d4i[4]= {-1, 0, 1, 0}, d4j[4]= {0, 1, 0, -1};
const int d8i[8]= {-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]= {0, 1, 1, 1, 0, -1, -1, -1};

int n,ans;
int a[100005][4];
int d[100005][4];

signed main()
{
//#ifndef ONLINE_JUDGE
//    hardio("digitssum");
//#endif
    fastIO;
    cin>>n;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=3; j++)
            cin>>a[i][j];
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=3; j++)
        {
            {
                for (int k=1; k<=3; k++)
                    if (k!=j)
                        d[i][j]=max(d[i][j],d[i-1][k]);
            }
            d[i][j]+=a[i][j];
        }



    }
    cout<<max(d[n][1],max(d[n][2],d[n][3]));
}
