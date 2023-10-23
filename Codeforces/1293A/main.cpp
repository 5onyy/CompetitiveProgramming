#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("T.INP","r",stdin);
    int tests;
    cin>>tests;
    while (tests--)
    {
        int n,s,k;
        cin>>n>>s>>k;
        vector<int> a(k);
        for (int i=0;i<k;i++)
            cin>>a[i];
//        for (auto i:a)
//            cout<<i<<" ";
        for (int i=0; i<=k; i++)
        {
            if (s-i>=1 && find(a.begin(),a.end(),s-i)==a.end())
            {
                cout<<i<<endl;
                break;
            }
            if (s+i<=n && find(a.begin(),a.end(),s+i)==a.end())
            {
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}
