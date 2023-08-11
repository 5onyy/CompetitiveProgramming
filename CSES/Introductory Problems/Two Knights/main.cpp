#include <bits/stdc++.h>

using namespace std;

#define sqr(x) (x)*(x)
#define ll long long

int main()
{
    ll n;
    cin>>n;
    cout<<0<<endl;
    for (ll i=2;i<=n;i++)
    {
        cout<<(sqr(i)*(sqr(i)-1))/2- 4*(i-1)*(i-2)<<endl;
    }
    return 0;
}
