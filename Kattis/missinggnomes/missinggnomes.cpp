#include<bits/stdc++.h>
using namespace std;
int visit[100001]={0},a[100000];
int n,k;
int main()
{
    cin>>n>>k;
    set<int> res;
    for (int i=0; i<k; i++)
    {
        cin>>a[i];
        visit[a[i]]++;
    }
    for (int i=1; i<=n; i++)
    {
        if (!visit[i])
            res.insert(i);
    }
    int i=0;
    while (!res.empty() && i<k)
    {
        if (*res.begin()< a[i])
        {
            cout<<*res.begin()<<endl;
            res.erase(*res.begin());
        }
        else
            cout<<a[i++]<<endl;
    }
    if (!res.empty())
    {
        while (!res.empty())
        {
            cout<<*res.begin()<<endl;
            res.erase(*res.begin());
        }
    }
    else if (i<k)
    {
        while (i<k)
            cout<<a[i++]<<endl;
    }
    return 0;
}

