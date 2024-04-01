#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(int a,int b)
{
    if ((a==1 && b==2) || (a==2 && b ==1))
    {
        cout<<"YES"<<endl;
        return;
    }
    if ((a==1 && b==1) || (a==2 && b==2))
    {
        cout<<"NO"<<endl;
        return;
    }
    if (a>b)
        swap(a,b);
    if (b==2*a || (a==b && a%3==0) )
    {
        cout<<"YES"<<endl;
        return;
    }
    int t=a+b;
    if (b<2*a && t%3==0)
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}

signed main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int a,b;
        cin>>a>>b;
        solve(a,b);
    }


    return 0;
}
