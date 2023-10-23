#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long a,b,s;
    cin>>a>>b>>s;
    a=abs(a);   b=abs(b);
    long long k=a+b;
    if ((s-k)%2==0 && s>=k)
        cout<<"Yes";
    else cout<<"No";
    return 0;
}
