#include <bits/stdc++.h>

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
        if ((n/2)%2!=0)
            cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            int sum=0;
            for (int i=2;i<=n;i+=2)
            {
                cout<<i<<" ";
                sum+=i;
            }
            int tmp=1,sum2=0;
            for (int i=1;i<=n/2-1;i++)
            {
                cout<<tmp<<" ";
                sum2+=tmp;
                tmp+=2;
            }
            cout<<sum-sum2<<endl;
        }
    }
    return 0;
}
