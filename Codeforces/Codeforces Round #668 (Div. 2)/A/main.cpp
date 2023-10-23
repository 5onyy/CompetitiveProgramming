#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main()
{
    freopen("T.INP","r",stdin);
    int tests;
    cin>>tests;
    while (tests--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for (int i=0;i<n;i++)
            cin>>a[i];
        for (int i=n-1;i>=0;i--)
            cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}
