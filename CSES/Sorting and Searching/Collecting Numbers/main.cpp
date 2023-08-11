#include <bits/stdc++.h>

using namespace std;

int n;
int id[200005];

void solve(int n)
{
    stack<int>  q;
    q.push(1e9);
    int ans=1,l=1;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        id[x]=i;
    }
    for (int i=1;i<=n;i++)
    {
        if (l>id[i])
            ans++;
        l=id[i];
    }
    cout<<ans;
}
int main()
{
    cin>>n;
    solve(n);
    return 0;
}
