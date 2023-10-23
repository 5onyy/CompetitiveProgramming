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
        vector<int> a(n);
        set<int> s;
        for (int i=0;i<n;i++)
        {
            cin>>a[i];  s.insert(a[i]);
        }
        if (s.size()==1)
        {
            cout<<"NO"<<endl;
            continue;
        }
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        cout<<"YES"<<endl;
        cout<<a[0]<<" "<<a[n-1]<<" ";
        for (int i=1;i<n-1;i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}
