#include <bits/stdc++.h>

using namespace std;
int a[100001],b[100001];
int ans;
int main()
{
    freopen("T.INP","r",stdin);
    int tests;
    cin>>tests;
    while (tests--)
    {
        int n,m;
        cin>>n>>m;
        for (int i=0; i<n; i++)
            cin>>a[i];
        for (int i=0; i<m; i++)
            cin>>b[i];
        bool ok=false;
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                if (a[i]==b[j])
                {
                    ok=true;
                    ans=a[i];
                    break;
                }
            }
            if (ok==true)
                break;
        }
        if (ok)
            {
                cout<<"YES"<<endl;
                cout<<1<<" "<<ans<<endl;
            }
        else
            cout<<"NO"<<endl;
    }
    return 0;
}

