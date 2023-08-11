#include <bits/stdc++.h>

using namespace std;

const long long mod=1e9+7;

long long mul(int n)
{
    int t=1;
    for (int i=1;i<=n;i++)
        t=(2*t)%(mod);
    return t;
}

int main()
{
    int n;
    cin>>n;
    cout<<mul(n);
    return 0;
}
