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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> ii;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ii> vii;

const ll BASE=311;
const ll MOD=1000000003;
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

int n,m,ans;
int a[1001][1001];

bool check(int i,int j)
{
    return(i<=n && i>=1 && j<=m && j>=1);
}

void dfs(int i,int j)
{
    a[i][j]=2;
    for (int k=0;k<4;k++)
    {
        int ui=d4i[k]+i;
        int uj=d4j[k]+j;
        if (!a[ui][uj] && check(ui,uj)) dfs(ui,uj);
    }
}

int main()
{
//    freopen(".INP","r",stdin);
//    freopen(".OUT","w",stdout);
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for (int j=0;j<m;j++)
            a[i+1][j+1]= (s[j]=='#') ? 1 :0;
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
            if (!a[i][j]) ans++,dfs(i,j);
    }
    cout<<ans;
}
