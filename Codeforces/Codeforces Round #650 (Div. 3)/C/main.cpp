#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tests;
    cin>>tests;
    while (tests--)
    {
        int n;
        cin>>n>>k;
        string s;
        cin>>s;
        for (int i=0;i<s.size();i++)
        {
            if (s[i]=='1')
            {
                for (int j=1;j<=k;j++)
                    s[i+j]=s[i-j]='2';
            }
        }
    }
    return 0;
}
