#include <bits/stdc++.h>

using namespace std;
long long a[1000001];
int main()
{
    //freopen("T.INP","r",stdin);
    long long tests;
    cin>>tests;
    while (tests--)
    {
        long long n=0,ans=0,res=0;
        cin>>n;
        for (int i = 1; i <= n; i++)
        {
            long long tmp;
            cin >> tmp;
            res  += tmp;
            if (res < 0)
            {
                ans += abs(res);
                res = 0;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
