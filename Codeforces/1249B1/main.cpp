#include <bits/stdc++.h>

using namespace std;
int p[300];
int n,ans;
int main()
{
    freopen("t.inp","r",stdin);
    int tests;
    cin>>tests;
    while (tests--)
    {
        memset(p,0,sizeof p);
        cin>>n;
        for (int i=1;i<=n;i++)
            cin>>p[i];
        for (int i=1;i<=n;i++)
        {
            ans=0;
            int tmp=p[i];
            while (tmp!=i)
            {
                ans++;
                tmp=p[tmp];
            }
            cout<<ans+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}
