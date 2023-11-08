#include <bits/stdc++.h>
#define maxn 20
#define Task ""
#define vt vector
#define pb push_back
#define pii pair <int, int>
#define mp make_pair
#define F first
#define S second
#define ll long long
#define mod 1000000007
using namespace std;
int n;
ll c[maxn][maxn], f[maxn];
ll dp[maxn][maxn];

void prepare()
{
    f[0] = 1;
    for (int i = 1; i < maxn; i++)
        f[i] = f[i-1]*i;
}

void solve()
{
    ll re = 1 + f[n];
    dp[0][0] = 1;
    for (int k = 2; k < n; k++)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= k; j++)
                dp[i][j] = dp[i-1][j-1] + j*dp[i-1][j];
        re += dp[n][k] * f[k];
    }
    cout << re << endl;
}

int main()
{
    freopen("T.INP","r",stdin);
    prepare();
    while (cin >> n)
    {
        if (n == -1) break;
        solve();
    }
    return 0;
}
