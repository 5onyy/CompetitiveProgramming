#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    string s1;
    map<string,string> dict;
    while (getline(cin,s))
    {
        if (s!="")
        {
            string s1="";
            int i=0;
            while (s[i]!=' ')
                s1=s1+s[i++];
            dict.insert(pair<string,string>(s.substr(i+1),s1));
        }
        else break;
    }
    while (cin>>s)
    {
        if (dict.find(s)==dict.end())
            cout<<"eh"<<endl;
        else
        cout<<dict[s]<<endl;
    }
    return 0;
}
