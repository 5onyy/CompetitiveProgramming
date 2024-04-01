#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    if (n%2==1)   cout<<0;
    else{
        int ans=1;
        for (int i=2;i<=n;i+=2)
            ans*=2;
        if (ans!=1) cout<<ans;
        else cout<<0;
    }

    return 0;
}
