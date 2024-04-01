#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tests;
    cin>>tests;
    while (tests--)
    {
        int n;
        cin>>n;
        bool bad=false;
        vector<int> a(n);
        for (int i=0;i<n;i++)
            cin>>a[i];
        sort(a.begin(),a.end());
        for (int i=0;i<n-1;i++)
        {
            if (abs(a[i+1]-a[i]) > 1)
            {
                bad=true;
                break;
            }
        }
        if (bad) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}
