#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll solve(ll i,ll j)
{
    if (i==1 && j==1)
        return 1;
    if (i>=j)
    {
        if (i%2==0)
            return i*i-(j-1);
        else return (i-1)*(i-1)+j;
    }
    if (j%2!=0)
        return j*j-(i-1);
    return (j-1)*(j-1)+i;
}

int main()
{
    ll  i,j;
    int t;
    cin>>t;
    while (t--)
    {
        cin>>i>>j;
        cout<<solve(i,j)<<endl;
    }

    return 0;
}
