#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n;

int main()
{
    int tests;
    cin>>tests;
    while (tests--)
    {
        cin>>n;
        ll t=1;
        vector<ll> a(n);
        for (int i=0;i<n;i++)
        {
            cin>>a[i];
            t*=a[i];
        }
        ll ans=t+(n-1);
        cout<<ans*2022<<endl;
    }
    return 0;
}
