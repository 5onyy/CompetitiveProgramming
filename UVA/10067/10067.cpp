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

int s1,s2,s3,s4,f1,f2,f3,f4;
int d[10][10][10][10],visit[10][10][10][10];

struct node{
    int x,y,z,t;
    node (int x,int y,int z,int t)
    {
        this->x=x;
        this->y=y;
        this->z=z;
        this->t=t;
    }
};

void bfs(int s1,int s2,int s3,int s4,int f1,int f2,int f3,int f4)
{
    d[s1][s2][s3][s4]=0;
    visit[s1][s2][s3][s4]=1;
    queue<node> q;
    q.push(node(s1,s2,s3,s4));
    while (!q.empty())
    {
        node u=q.front();
        if (u.x==f1 && u.y==f2 && u.z==f3 && u.t==f4)   break;
        q.pop();
        for (int i=-1;i<=1;i++)
        {
            int v=u.x+i;
            if (v==10)  v=0;
            if (v==-1)  v=9;
            if (i==0) continue;
            else if (!visit[v][u.y][u.z][u.t] && d[v][u.y][u.z][u.t]!=-1)
                d[v][u.y][u.z][u.t]=d[u.x][u.y][u.z][u.t]+1, visit[v][u.y][u.z][u.t]=1,
                q.push(node(v,u.y,u.z,u.t));
        }
        for (int i=-1;i<=1;i++)
        {
            int v=u.y+i;
            if (v==10)  v=0;
            if (v==-1)  v=9;
            if (i==0) continue;
            else if (!visit[u.x][v][u.z][u.t] && d[u.x][v][u.z][u.t]!=-1)
                d[u.x][v][u.z][u.t]=d[u.x][u.y][u.z][u.t]+1, visit[u.x][v][u.z][u.t]=1,
                q.push(node(u.x,v,u.z,u.t));
        }
        for (int i=-1;i<=1;i++)
        {
            int v=u.z+i;
            if (v==10)  v=0;
            if (v==-1)  v=9;
            if (i==0) continue;
            else if (!visit[u.x][u.y][v][u.t] && d[u.x][u.y][v][u.t]!=-1)
                d[u.x][u.y][v][u.t]=d[u.x][u.y][u.z][u.t]+1, visit[u.x][u.y][v][u.t]=1,
                q.push(node(u.x,u.y,v,u.t));
        }
        for (int i=-1;i<=1;i++)
        {
            int v=u.t+i;
            if (v==10)  v=0;
            if (v==-1)  v=9;
            if (i==0) continue;
            else if (!visit[u.x][u.y][u.z][v] && d[u.x][u.y][u.z][v]!=-1)
                d[u.x][u.y][u.z][v]=d[u.x][u.y][u.z][u.t]+1, visit[u.x][u.y][u.z][v]=1,
                q.push(node(u.x,u.y,u.z,v));
        }
    }
}

int main()
{
    freopen("10067.INP","r",stdin);
    freopen("10067.OUT","w",stdout);
    int tests;
    cin>>tests;
    while (tests--)
    {
        cin>>s1>>s2>>s3>>s4;
        cin>>f1>>f2>>f3>>f4;
        memset(d,0,sizeof d);
        memset(visit,0,sizeof visit);
        d[f1][f2][f3][f4]=-2;
        int n;
        cin>>n;
        while (n--)
        {
            int t1,t2,t3,t4;
            cin>>t1>>t2>>t3>>t4;
            d[t1][t2][t3][t4]=-1;
        }
        string s;
        getline(cin,s);
        bfs(s1,s2,s3,s4,f1,f2,f3,f4);
        if (d[f1][f2][f3][f4]!=-2)
            cout<<d[f1][f2][f3][f4]<<endl;
        else cout<<-1<<endl;
    }
}
