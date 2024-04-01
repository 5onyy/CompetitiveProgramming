#include <bits/stdc++.h>

using namespace std;
int n;
int main()
{
    //freopen("T.INP","r",stdin);
    int tests;
    cin>>tests;
    while (tests--)
    {
        int dem=0;
        cin>>n;
        vector<int> a(n);
        for (int i=0;i<n;i++)
            cin>>a[i];
        for (int i=0;i<n-1;i++)
            if (a[i]==a[i+1])
                dem++;
        if (dem==n-1)   cout<<n<<endl;
        else cout<<1<<endl;
    }
    return 0;
}
