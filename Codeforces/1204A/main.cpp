#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int cnt=0;
    for (int i=0;i<s.size();i++)
        if (s[i]=='1')
            cnt++;
    if (cnt==1 && s.size()&1)
    {
        cout<<(s.size()-1)/2;
    }
    else if (s.size()&1 && cnt>1)
        cout<<(s.size()+1)/2;
    else cout<<s.size()/2;
    return 0;
}
