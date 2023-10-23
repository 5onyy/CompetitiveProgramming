#include <bits/stdc++.h>

using namespace std;

int n,m;

int main()
{
    int tests;
    cin>>tests;
    while (tests--)
    {
                long long s=0;
        cin>>n>>m;
        vector<long long> a(n);
        vector<long long> b(m);
        for (int i=0;i<n;i++)
            cin>>a[i];
        for (int i=0;i<m;i++)
            cin>>b[i];
        for (int i=0;i<m;i++)
        {
            auto t=min_element(a.begin(),a.end());
                *t=b[i];
        }
        for (int i=0;i<n;i++)
            s+=a[i];
        cout<<s<<endl;
    }


    return 0;
}
