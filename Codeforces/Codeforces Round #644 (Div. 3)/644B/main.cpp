#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tests;
    cin>>tests;
    while (tests--)
    {
        int n,ans=INT_MAX;
        cin>>n;
        vector<int> a(n);
        for (int i=0;i<n;i++)
            cin>>a[i];
        sort(a.begin(),a.end());
        for (int i=0;i<n-1;i++)
            ans=min(ans,a[i+1]-a[i]);
        cout<<ans<<endl;
    }
    return 0;
}
