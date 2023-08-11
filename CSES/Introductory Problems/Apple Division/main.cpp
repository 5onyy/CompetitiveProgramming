#include <bits/stdc++.h>

using namespace std;

long long a[20];

void solve(int n)
{
    long long s=0,ans=0;
    for (int i=0;i<n;i++)
        s+=a[i];
    //cout<<s<<endl;
    for (int i=1;i<((1<<n)-1);i++)
    {
        long long s2=0;
        for (int j=0;j<n;j++)
        {
            if (i&(1<<j))
                s2+=a[j];
        }
        if (s2<=s/2)
            ans=max(ans,s2);
    }
    cout<<abs(s-2*ans);
}

int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    solve(n);
    return 0;
}
