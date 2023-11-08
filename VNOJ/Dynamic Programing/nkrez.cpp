#include <bits/stdc++.h>

using namespace std;
int n;
int dp[10005];
struct node{
    int s,f;
    node (int s,int f)
    {
        this->s=s;  this->f=f;
    }
};
bool cmp(const node &x,const node &y)
{
    return (x.f<y.f);
}
vector<node> v;
int main()
{
    scanf("%d",&n);
    v.push_back(node(0,0));
    for (int i=1;i<=n;i++)
    {
        int t1,t2;
        scanf("%d %d",&t1,&t2);
        v.push_back(node(t1,t2));
    }
    sort(v.begin(),v.end(),cmp);
    for (int i=1;i<v.size();i++)
    {
        dp[i]=v[i].f-v[i].s;
        int tmp=dp[i];
        for (int j=1;j<i;j++)
        {
            if (v[i].s>=v[j].f)
                dp[i]=max(dp[j]+tmp,dp[i]);
            else dp[i]=max(dp[i],dp[j]);
        }
    }
    printf("%d",dp[n]);
    return 0;
}
