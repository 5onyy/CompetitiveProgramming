//#include <cassert>
//#include <climits>
//#include <cmath>
//#include <complex>
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <ctime>
//#include <algorithm>
//#include <bitset>
//#include <deque>
//#include <fstream>
//#include <functional>
//#include <iomanip>
//#include <iostream>
//#include <iterator>
////#include <list>
//#include <map>
//#include <numeric>
//#include <queue>
//#include <set>
//#include <sstream>
//#include <stack>
//#include <string>
//#include <utility>
//#include <vector>
//
//using namespace std;
//
//#define fastIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
//#define fi first
//#define se second
//#define pb push_back
//#define pf push_front
//#define mp make_pair
//#define inf 999999999
//#define sz(x) (int)(x).size()
//
//typedef long long ll;
//typedef unsigned long long ull;
//typedef long double ld;
//typedef pair<int,int> ii;
//typedef unsigned long long ull;
//typedef vector<int> vi;
//typedef vector<ii> vii;
//
//const ll BASE=311;
//const ll MOD=1000000003;
//const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
//const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
//
//
//int cnt=0;
//map<string,int> m;
//
//int main()
//{
//    freopen("T.INP","r",stdin);
//    freopen("T.OUT","w",stdout);
//    fastIO;
//    string str;
//    while (getline(cin,str))
//    {
//        cnt++;
//        m[str]++;
//    }
//    map<string,int>::iterator itr;
//    for (itr=m.begin();itr!=m.end();++itr)
//        cout<<fixed<<setprecision(4)<<itr->fi<<" "<<((ld)itr->se /cnt)*(ld)100<<endl;
//}
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define maxn 10010
using namespace std;
typedef long long LL;
struct Edge {
    int to, ne;
}edge[maxn];
int fa[maxn], son[maxn], dep[maxn], sz[maxn], ne[maxn], top[maxn], tot, in[maxn];
void add(int u, int v) {
    edge[tot] = {v, ne[u]};
    ne[u] = tot++;
}
void dfs1(int u, int f, int depth) {
//    printf("%d\n", u);
    dep[u] = depth, fa[u] = f, son[u] = -1, sz[u] = 1;
    for (int i = ne[u]; ~i; i = edge[i].ne) {
        int v = edge[i].to;
        dfs1(v, u, depth+1);
        sz[u] += sz[v];
        if (son[u] == -1 || sz[son[u]] < sz[v]) son[u] = v;
    }
}
void dfs2(int u, int sp) {
    top[u] = sp;
    if (son[u] == -1) return;
    dfs2(son[u], sp);
    for (int i = ne[u]; ~i; i = edge[i].ne) {
        int v = edge[i].to;
        if (v == son[u]) continue;
        dfs2(v, v);
    }
}
int lca(int u, int v) {
    int fau = top[u], fav = top[v];
    while (fau != fav) {
        if (dep[fau] < dep[fav]) swap(fau, fav), swap(u, v);
        u = fa[fau], fau = top[u];
    }
    return dep[u] < dep[v] ? u : v;
}
void work() {
    tot = 0; memset(ne, -1, sizeof ne); memset(in, 0, sizeof in);
    int n, u, v;
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &u, &v);
        add(u, v);
        ++in[v];
    }
    int i = 1;
    for (;i <= n; ++i) if (!in[i]) break;
    dfs1(i, -1, 0);
    dfs2(i, i);
    scanf("%d%d", &u,&v);
    printf("%d\n", lca(u, v));
}
int main() {
//    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
