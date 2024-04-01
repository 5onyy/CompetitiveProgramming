#include <bits/stdc++.h>

using namespace std;
int a[1000],b[1000];
int main()
{
    //freopen("T.INP","r",stdin);
    int tests;
    cin>>tests;
    while (tests--)
    {
        int n;
        long long ans=0;
        cin>>n;
        int minA=INT_MAX;
        int minB=INT_MAX;
        for (int i=0; i<n; i++)
        {
            cin>>a[i];
            minA=min(a[i],minA);
        }
        for (int i=0; i<n; i++)
        {
            cin>>b[i];
            minB=min(b[i],minB);
        }
        for (int i=0; i<n; i++)
        {
            if (a[i]>minA && b[i]>minB)
            {
                int tmp=min(a[i]-minA,b[i]-minB);
                ans+=tmp;
                a[i]-=tmp;
                b[i]-=tmp;
            }
            if (a[i]>minA)
            {
                ans+=a[i]-minA;
                a[i]=minA;
            }
            if (b[i]>minB)
            {
                ans+=b[i]-minB;
                b[i]=minB;

            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
