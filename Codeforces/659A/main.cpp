#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,vt,b;
    cin>>n>>vt>>b;
    int sl=abs(b)%n;
    if (b<0)    sl=-sl;
    vector<int> a(5*n);
    for (int i=1;i<=n;i++)
        a[i]=i;
    for (int i=1;i<=n;i++)
        a[n+i]=i;
    for (int i=1;i<=n;i++)
        a[2*n+i]=i;
    cout<<a[vt+n+sl];
    return 0;
}
