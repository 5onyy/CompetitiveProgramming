#include <iostream>

using namespace std;

int main()
{
    int tests;
    cin>>tests;
    while (tests--){
        string s;
        cin>>s;
        if (s.size()==1 || s=="()") cout<<"NO\n";
        else {
            string t1="";
            for (int i=1;i<=s.size();i++) t1+='(';
            for (int i=1;i<=s.size();i++) t1+=')';
            if (t1.find(s) != string::npos){
                t1="";
                for (int i=1;i<=s.size();i++)   t1+="()";
                if (t1.find(s) != string::npos)     cout<<"NO\n";
                else cout<<"YES\n"<<t1<<'\n';
            }
            else cout<<"YES\n"<<t1<<'\n';
        }
    }
    return 0;
}
