#include <bits/stdc++.h>

using namespace std;

int n;

void solve(int n){
    int cur=-1,ans=0;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if (cur<=x)
        {
            ans++;
            cur=x;
        }
    }
    cout<<ans;
}

int main()
{
    cin>>n;
    solve(n);
    return 0;
}
