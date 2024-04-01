#include<bits/stdc++.h>
using namespace std;
int a[200001],n;
long long res=0;
int main()
{
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
     sort(a,a+n,greater<int>());
     for (int i=0;i<n;i++)
    {
            if (i%3==2)
                res+=a[i];
    }
    cout<<res;
    return 0;
}
