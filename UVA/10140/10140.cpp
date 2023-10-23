#include<bits/stdc++.h>
using namespace std;
int n,x,y,min_ans=9999999,max_ans=0;
pair<int,int> ans1,ans2;
void sang(long long l, long long r)
{
    vector<bool>  a(r - l + 1, true);
    vector<long long> res;
    min_ans=9999999;
    max_ans=0;
    for (long long i = 2; i * i <= r; ++i)
    {
        for (long long j = max(i * i, (l + i - 1) / i * i); j <= r; j += i) //tim boi nho nhat cua i>=L
        {
            a[j - l] = false;
        }
    }
    if (1 >= l)
    {
        a[1 - l] = false;
    }
    for (long long x = l; x <= r; ++x)
    {
        if (a[x - l])
        {
            res.push_back(x);
        }
    }
    if (res.size()<2)
            cout<<"There are no adjacent primes."<<endl;
        else
        {
            for (int i=0;i<res.size()-1;i++)
            {
                if (res[i+1]-res[i]<min_ans)
                {
                    ans1.first=res[i];
                    ans1.second=res[i+1];
                    min_ans=res[i+1]-res[i];
                }
                if (res[i+1]-res[i]>max_ans)
                {
                    ans2.first=res[i];
                    ans2.second=res[i+1];
                    max_ans=res[i+1]-res[i];
                }
            }
            cout<<ans1.first<<","<<ans1.second<<" are closest, "<<ans2.first<<","<<ans2.second<<" are most distant."<<endl;
        }
}
int main()
{
    freopen("10140.INP","r",stdin);
    freopen("10140.OUT","w",stdout);
    while (cin>>x>>y)
    {
        sang(x,y);
    }
}
