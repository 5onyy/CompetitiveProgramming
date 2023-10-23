#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int l=n/2+1,r=n/2+1;
    int le=1,chan=2;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (j>=l && j<=r)
                cout<<le<<" " , le+=2;
            else cout<<chan<<" ", chan+=2;
        }
        cout<<endl;
        if (i<(n+1)/2)  l--,r++;
        else l++, r--;
    }

    return 0;
}
