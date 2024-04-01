#include<bits/stdc++.h>
using namespace std;
long long n;
bool scp(long long n)
{
    return (sqrt(n)==trunc(sqrt(n)));
}
int main()
{
    set<long long> res;
    cin>>n;
    for (int i=1;i<=trunc(sqrt(n));++i)
    {
        if (n%i==0)
        {
            cout<<i-1<<" ";
            res.insert(n/i);
        }
    }
    if (scp(n))
        res.erase(*res.begin());
    while (!res.empty())
    {
        cout<<*(res.begin())-1<<" ";
        res.erase(*(res.begin()));
    }
    return 0;
}
