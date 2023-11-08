#include <bits/stdc++.h>
using namespace std;
int n,ansx=0,ansy=0;
long long ans=0;
int l[500002],r[500002],a[500002];
void solve()
{
    ansx=0,ansy=0,ans=0;
    memset(l,0,sizeof l);
    memset(r,0,sizeof r);
    deque <int> dq;
    dq.push_front(0);
    for (int i=1;i<=n;i++)
    {
        while (!dq.empty() && a[dq.back()]>=a[i])
            dq.pop_back();
        l[i]=dq.back()+1;
        dq.push_back(i);
    }
    dq.clear();
    dq.push_back(n+1);
    for (int i=n;i>=1;i--)
    {
        while (!dq.empty() && a[dq.front()]>=a[i])
            dq.pop_front();
        r[i]=dq.front()-1;
        dq.push_front(i);
    }
    for (int i=1;i<=n;i++)
    {
        long long tmp=(r[i]-l[i]+1)*a[i];
        if (ans==tmp)
        {
            if (l[i]<ansx)
            {
                ansx=l[i];  ansy=r[i];
            }
        }
        if (ans<tmp)
        {
            ans=tmp;
            ansx=l[i];  ansy=r[i];
        }
    }
}
int main()
{
    //freopen("KAGAIN.INP","r",stdin);
    //freopen("KAGAIN.OUT","w",stdout);
    int tests;
    scanf("%d",&tests);
    while (tests--)
    {
        memset(a,0,sizeof a);
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        solve();
        printf("%lli %d %d\n",ans,ansx,ansy);
    }
    return 0;
}
