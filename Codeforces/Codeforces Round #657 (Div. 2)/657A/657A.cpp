#include <bits/stdc++.h>

using namespace std;
string s,s1;
int t;
int main()
{
    cin>>t;
    while (t--)
    {
        bool flag=false;
        int d=0,n;
        cin>>n;
        cin>>s;
        for (int i=0; i<=n-7; i++)
        {
            s1=s.substr(i,i+7);
            if (s1=="abacaba")
                flag=true;
        }
        if (flag==false)
        {
            for (int i=0; i<=n-7; i++)
            {
                if (s1[0]=='?')
                    s1[0]='a';
                if (s1[1]=='?')
                    s1[1]='b';
                if (s1[2]=='?')
                    s1[2]='a';
                if (s1[3]=='?')
                    s1[3]='c';
                if (s1[4]=='?')
                    s1[4]='a';
                if (s1[5]=='?')
                    s1[5]='b';
                if (s1[6]=='?')
                    s1[6]='a';
                if (s1=="abacaba")
                {
                    flag=true;
                    s[i]='a';
                    s[i+1]='b';
                    s[i+2]='a';
                    s[i+3]='c';
                    s[i+4]='a';
                    s[i+5]='b';
                    s[i+6]='a';
                }
            }
            }
            if (flag==true)
            {
                for (int i=0; i<n; ++i)
                {
                    if (s[i]=='?')
                        s[i]='z';
                }
                for (int i=0; i<=n-7; i++)
                {
                    s1=s.substr(i,7);
                    if (s1=="abacaba")
                        d++;
                }
            }
            if (d==1)
                cout<<"YES"<<endl<<s<<endl;
            else if (d!=1)
                cout<<"NO"<<endl;
        }
        return 0;
    }
