#include<bits/stdc++.h>
using namespace std;
int n,d=0,x;
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>x;
        if (x<0)
            d++;
    }
    cout<<d;
    return 0;
}
