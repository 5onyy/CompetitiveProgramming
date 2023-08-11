#include <bits/stdc++.h>
#define inf 99999
using namespace std;
int n;
int a[1001];
int main()
{
    freopen("T.INP","r",stdin);
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n;
        string s="abcdefghijklmnopqrstuvwxyxabcdefghijklmnopqrstuvwxyx";
        memset(a,inf,sizeof a);
        for (int i=1;i<=n;i++)
            cin>>a[i];
        for (int i=1;i<=n;i++)
        {
            cout<<s.substr(0,a[i])<<endl;
        }
    }
    return 0;
}
