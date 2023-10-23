#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tests;
    cin>>tests;
    while (tests--)
    {
        int a,b;
        cin>>a>>b;
        if (a>b) cout<<"YES"<<endl;
        else if (a==2 && b>3)
            cout<<"NO"<<endl;
        else if (a==1 && b>1)
            cout<<"NO"<<endl;
        else if (a==3 && b>3)
            cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}
