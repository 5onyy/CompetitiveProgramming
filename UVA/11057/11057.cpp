#include<bits/stdc++.h>
#include<vector>
using namespace std;
int money,n;
int main()
{
    freopen("11057.INP","r",stdin);
    freopen("11057.OUT","w",stdout);
    while (cin>>n)
    {
        vector<int>v;
        for (int i=0;i<n;i++)
        {
            int tmp;
            cin>>tmp;
            v.push_back(tmp);
        }
        cin>>money;
        sort(v.begin(),v.end());
        auto v1=lower_bound(v.begin(),v.end(),money/2);
        while (true)
        {
            if (binary_search(v.begin(), v1, money-*v1))
                {
                    cout<<"Peter should buy books whose prices are "<<money-*v1<<" and "<<*v1<<"."<<endl;
                    break;
                }
            else ++v1;
        }
    }
    return 0;
}
