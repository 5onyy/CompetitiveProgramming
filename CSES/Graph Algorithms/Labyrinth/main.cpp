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

int n,m;
int a[1001][1001],d[1001][1001];
ii start,key;
vector<char> ans;

bool check(int i,int j)
{
    return (i>=1 && i<=n && j>=1 && j<=m);
}

void bfs(int i,int j)
{
    queue<ii> q;
    a[i][j]=2;
    d[i][j]=0;
    q.push(ii(i,j));
    while (!q.empty())
    {
        int ui=q.front().fi;
        int uj=q.front().se;
        q.pop();
        for (int k=0;k<4;k++)
        {
            int uii=d4i[k]+ui;
            int ujj=d4j[k]+uj;
            if (check(uii,ujj) && !a[uii][ujj])
                {a[uii][ujj]=2; d[uii][ujj]=d[ui][uj]+1; q.push(ii(uii,ujj));}
        }
    }
}

void solve(int i,int j)
{
    queue<ii> q;
    q.push(ii(i,j));
    while (!q.empty())
    {
        int ui=q.front().fi;
        int uj=q.front().se;
        q.pop();
        for (int k=0;k<4;k++)
        {
            int uii=d4i[k]+ui;
            int ujj=d4j[k]+uj;
            if (check(uii,ujj) && d[uii][ujj]+1==d[ui][uj])
            {
                if (k==0) ans.pb('D');
                if (k==1) ans.pb('L');
                if (k==2) ans.pb('U');
                if (k==3) ans.pb('R');
                q.push(ii(uii,ujj));
                break;
            }
        }
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
        {
            if (s[j]=='A')  start=ii(i+1,j+1);
            else if (s[j]=='B')  key=ii(i+1,j+1);
            else a[i+1][j+1]= (s[j]=='#') ? 1 :0;
        }
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            d[i][j]=INT_MAX;
    bfs(start.fi,start.se);
//    for (int i=1;i<=n;i++)
//    {
//        for (int j=1;j<=m;j++)
//            cout<<d[i][j]<<" ";
//        cout<<endl;
//    }
    if (d[key.fi][key.se]!=INT_MAX)
    {
        cout<<"YES"<<endl;
        cout<<d[key.fi][key.se]<<endl;
        solve(key.fi,key.se);
        for (int i=sz(ans)-1;i>=0;i--)
            cout<<ans[i];
    }
    else cout<<"NO";
}
