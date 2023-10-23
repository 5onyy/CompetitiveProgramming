#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tests;
    cin>>tests;
    while (tests--)
    {
        int n,lmax=0,tmp=0,sum;
        cin>>n>>k;
        for (int i=1;i<=n;i++)
            cin>>a[i];
        for (int i=1;i<=n/2;i++)
        {
            d[a[i]+a[n-i+1]]++;
            if (d[a[i]+a[n-i+1]]>lmax)
            {
                lmax=d[a[i]+a[n-i+1]];
                sum=a[i]+a[n-i+1];
            }
        }
        for (int i=1;i<=n/2;i++)
        {

        }
    }
    return 0;
}
