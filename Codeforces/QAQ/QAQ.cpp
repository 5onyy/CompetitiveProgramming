#include <bits/stdc++.h>

using namespace std;
string s;
int main()
{
    int ans=0;
    cin>>s;
    int n=s.size();
    for (int i=0;i<n-2;++i)
    {
        for (int j=i+1;j<n-1;++j)
        {
            for (int k=j+1;k<n;++k)
                if (s[i]=='Q' && s[j]=='A' && s[k]=='Q')
                    ans++;
        }
    }
    cout<<ans;
    return 0;
}
