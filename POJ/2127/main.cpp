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

using namespace std;
int sum [305] [305]; // build a post office between a minimum i to j consumption
int p[305];
int dp [305] [305]; // i villages built before the minimum consumption of the j-th post office

int main()
{
    int n,k;
    while(~scanf("%d%d",&n,&k))
    {
        memset(dp,0x3f,sizeof(dp));
        memset(sum,0,sizeof(sum));
        p[0]=0;

        for(int i=1;i<=n;i++)
        {
            scanf("%d",&p[i]);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                sum[i][j]=sum[i][j-1]+p[j]-p[(i+j)/2];
            }
            dp[i][1]=sum[1][i];
            dp[i][i]=0;
        }
        for(int j=2;j<=k;j++)
        {
            for(int i=j+1;i<=n;i++)
            {
                for(int k=1;k<i;k++)
                {
                    dp[i][j]=min(dp[i][j],dp[k][j-1]+sum[k+1][i]);
                }
            }
        }
        printf("%d\n",dp[n][k]);
    }
    return 0;
}
