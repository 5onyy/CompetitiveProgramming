#include <bits/stdc++.h>

using namespace std;
string s;
int main()
{
    cin>>s;
    cout<<s[0];
    for (int i=1;i<s.size();++i)
    {
        if (s[i-1]=='-')    cout<<s[i];
    }
    return 0;
}
