#include <bits/stdc++.h>

using namespace std;
string s;
int main()
{
    int tests;
    cin>>tests;
    while (tests--)
    {
        int n;
        cin>>n;
        s="";
        int sl=(n+3)/4;
        for (int i=1;i<=sl;i++)
            s=s+"8";
        for (int i=1;i<=n-sl;i++)
            s="9"+s;
        cout<<s<<endl;
    }
    return 0;
}
