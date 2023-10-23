#include<bits/stdc++.h>
using namespace std;
int n;
long long res=1000000001;
int main()
{
    int p[10];
    pair<int,int> a[10];
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        a[i].first=t1;
        a[i].second=t2;
    }
    for (int i=0;i<n;i++)
        p[i]=i;
    for (int i=1;i<(1<<n);i++)
    {
        int sour=1,bittered=0;;
        for (int j=0;j<n;j++)
        {
            if (i&(1<<j))
                {
                    sour=sour*a[j].first;
                    bittered+=a[j].second;
                }
        }
        if (abs(sour-bittered)<res)
            res=abs(sour-bittered);
    }
    cout<<res;
}
