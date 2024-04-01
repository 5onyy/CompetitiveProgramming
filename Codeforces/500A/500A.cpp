#include <bits/stdc++.h>

using namespace std;
int n,t,tmp;
int a[100001];
bool flag=true;
int main()
{
    cin>>n>>t;
    for (int i=1;i<n;i++)
    {
        cin>>a[i];
    }
    for (tmp=1;tmp<t;tmp+=a[tmp]);
    if (tmp==t) cout<<"YES";
    else cout<<"NO";
    return 0;
}
