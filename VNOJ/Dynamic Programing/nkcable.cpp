#include <bits/stdc++.h>
#define inf 9999999
using namespace std;
int n;
int a[250001],dp[250001];
int main()
{
    cin>>n;
    for (int i=2;i<=n;i+=1)
        cin>>a[i];
    dp[1]=inf;  dp[0]=0;
    for (int i=2;i<=n;i++)
        dp[i]=min(dp[i-1]+a[i],dp[i-2]+a[i]);
    cout<<dp[n];
    return 0;
}
