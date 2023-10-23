#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

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
typedef pair<ld,int> ldi;
typedef pair<double, int> di;
typedef pair<int,int> ii;
typedef unsigned long long ull;
typedef vector <ldi> vld;
typedef vector<int> vi;
typedef vector <ii> vii;
typedef vector<di> vd;

const ll BASE=311;
const ll MOD=1000000003;
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

int n,dem;
vector<vd> a;
double d[1001];
vii td;

void dijkstra(int s)
{

    for (int i=1;i<=n;i++) d[i] = 1e7;
    //    d[i]=sqrt((ld)(td[1].fi-td[i].fi)*(ld)(td[1].fi-td[i].fi) + (ld)(td[1].se-td[i].se)*(ld)(td[1].se-td[i].se));
    priority_queue<di, vector<di>, greater<di> > q;
    d[s] = 0;
    q.push(di(0,s));
    while (!q.empty())
    {
        int u=q.top().se;
        q.pop();
        for (int i=0;i<sz(a[u]);i++)
        {
            int v=a[u][i].se;
            double w=a[u][i].fi;
            if (d[v]> max(d[u],w))
                d[v]=max(d[u],w),   q.push(di(d[v],v));
        }
    }
}

int main()
{
    while (cin>>n && n)
    {
        dem++;
        td.clear();
        td.resize(n+1);
        a.clear();
        a.resize(n+1);
        for (int i=1;i<=n;i++)
        {
            int t1,t2;
            cin>>t1>>t2;
            td[i]=ii(t1,t2);
        }
        for (int i=1;i<=n;i++)
        {
            for (int j=i+1;j<=n;j++)
            {
                a[i].pb(di( sqrt((double)(td[i].fi-td[j].fi)*(ld)(td[i].fi-td[j].fi) + (double)(td[i].se-td[j].se)*(td[i].se-td[j].se)), j ));
                a[j].pb(di( sqrt((double)(td[i].fi-td[j].fi)*(ld)(td[i].fi-td[j].fi) + (double)(td[i].se-td[j].se)*(td[i].se-td[j].se)), i ));
            }
        }
        dijkstra(1);
        cout<<"Scenario #"<<dem<<"\n";
        cout<<setprecision(3)<<fixed<<"Frog Distance = "<<d[2] <<"\n\n";
    }
}
