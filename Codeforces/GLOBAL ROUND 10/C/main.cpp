#include <bits/stdc++.h>

using namespace std;
long long n;
int main()
{
    long long tests;
    cin>>tests;
    while (tests--)
    {
        long long ans=0;
        cin>>n;
        vector<long long> a(n);
        for (long long i=0;i<n;i++)
            cin>>a[i];
        for (long long i=0;i<n-1;i++)
        {
            if (a[i]>a[i+1])
            {
                long long hieu=a[i]-a[i+1];
                ans+=hieu;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
