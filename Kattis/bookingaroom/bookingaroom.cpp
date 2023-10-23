#include<bits/stdc++.h>
using namespace std;
bool a[101];
int r,n,x;
int main()
{
    cin>>r>>n;
    memset(a,true,sizeof(a));
    if (n==r)
        cout<<"too late";
    else
    {
        for (int i=1; i<=n; i++)
        {
            cin>>x;
            a[x]=false;
        }
        for (int i=1; i<=r; i++)
        {
            if (a[i]==true)
            {
                cout<<i;
                break;
            }
        }
    }
    return 0;
}
