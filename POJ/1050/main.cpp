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
typedef pair<int,int> ii;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ii> vii;

const ll BASE=311;
const ll MOD=1000000003;
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

int a[105][105],p[105][105];
int n,ans=INT_MIN;

int hcn(int x1,int y1,int x2,int y2)
{
    return (p[x2][y2]-p[x1-1][y2]-p[x2][y1-1]+p[x1-1][y1-1]);
}

int main()
{
    freopen("T.INP","r",stdin);
    freopen("T.OUT","w",stdout);
    fastIO;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            p[i][j]=p[i][j-1]+p[i-1][j]-p[i-1][j-1]+a[i][j];
        }
    }
    for (int x1=1;x1<=n;x1++)
        for (int y1=1;y1<=n;y1++)
            for (int x2=x1;x2<=n;x2++)
                for (int y2=y1;y2<=n;y2++)
                    if (hcn(x1,y1,x2,y2)>ans)
                        ans=hcn(x1,y1,x2,y2);
    cout<<ans;
}
