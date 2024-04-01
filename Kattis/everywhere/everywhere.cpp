#include<bits/stdc++.h>
#include<string>
using namespace std;
int y=0,d=0,t,n;
string s;
string a[101];
bool check(string s)
{
    for (int i=1;i<=y;i++)
    {
        if (a[i]==s)
            return true;
    }
    return false;
}
int main()
{
    cin>>t;
    for (int i=1;i<=t;i++)
    {
        cin>>n;
        for (int j=1;j<=n;j++)
        {
            cin>>s;
            if (check(s)==false)
                {
                    y++;
                    a[y]=s;
                    d++;
                }
        }
        cout<<d<<endl;
        d=0;
        y=0;
    }
    return 0;
}
