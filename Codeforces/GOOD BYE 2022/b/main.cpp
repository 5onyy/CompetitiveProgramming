#include <bits/stdc++.h>

using namespace std;

int n,k;

int main()
{
    int tests;
    cin>>tests;
    while (tests--)
    {
        cin>>n>>k;
        if (k==1 || k==n)
            for (int i=1;i<=n;i++)
                cout<<i<<" ";
        else
        {
            int maxx=n+1;
            for (int i=1;i<=n/2;i++)
                cout<<maxx-i<<" "<<i<<" ";
            if (n&1)
                cout<<n/2+1;
        }
        cout<<"\n";
    }
    return 0;
}
