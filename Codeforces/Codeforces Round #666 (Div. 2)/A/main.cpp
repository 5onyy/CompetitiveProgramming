#include <bits/stdc++.h>

using namespace std;
int d[10001];
int main()
{
    int tests;
    cin>>tests;
    while (tests--)
    {
        memset(d,0,sizeof d);
        bool bad=false;
        int n;
        string s;
        cin>>n;
        for (int i=0;i<n;i++)
        {
            cin>>s;
            for (int j=0;j<s.size();j++)
                d[s[j]]++;
        }
        for (int i='a';i<='z';i++)
        {
            if (d[i]%n!=0)
            {
                bad=true;
                break;
            }
        }
        if (bad) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}
