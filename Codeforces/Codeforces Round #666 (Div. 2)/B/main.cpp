#include <bits/stdc++.h>
#define inf 1000000000000000011

typedef long long ll;

using namespace std;

int n;
ll a[100001];
ll ans=inf;

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%lli",&a[i]);
    sort(a,a+n);
    for (int val=1;val<=100000;val++)
    {
        bool bad=false;
        ll tmp=1,res=0;
        for (int i=1;i<n;i++)
        {
            tmp*=val;
            if (tmp>inf)
            {
                bad=true;
                break;
            }
        }
        if (bad) break;
        tmp=1;
        for (int i=0;i<n;i++)
        {
            res+=abs(tmp-a[i]);
            tmp*=val;
        }
        ans=min(ans,res);
    }
    printf("%lli",ans);
    return 0;
}
