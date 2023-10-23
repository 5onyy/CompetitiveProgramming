#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[10000000];
ll maxnum(ll n)
{
    ll ans=0;
    while (n!=0)
    {
        ll MOD=n%10;
        ans=max(ans,MOD);
        n/=10;
    }
    return ans;
}
int main()
{
    ll n;
    cin>>n;
    for (ll i=1;i<=9;i++)
        dp[i]=1;
    for (ll i=10;i<=n;i++)
        dp[i]=dp[i-maxnum(i)]+1;
    cout<<dp[n];
    return 0;
}
