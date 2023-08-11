#include<bits/stdc++.h>>
int a[1001],x,y,n;
using namespace std;
int gcd(int x,int y)
{
    if (y==0) return x;
    else return gcd(y,x%y);
}
int main()
{
    freopen("10407.INP","r",stdin);
    freopen("10407.OUT","w",stdout);
    while (cin>>x)
    {
        if (x==0)
            break;
        else
        {
            n=0;    a[n]=x;
            while (cin>>y)
            {
                if (y==0)
                    break;
                else a[++n]=y;
            }
            int ans = abs(a[1]-a[0]);
            for(int i = 2; i <=n; i++)
            {
                ans = gcd(ans, abs(a[i]-a[i-1]));
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
