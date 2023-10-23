#include<bits/stdc++.h>
using namespace std;
int x,n,p;
long long s;
int main()
{
    cin>>x>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>p;
        s+=(x-p);
    }
    cout<<s+x;
    return 0;
}
