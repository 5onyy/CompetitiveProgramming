#include<bits/stdc++.h>
#include<string>
using namespace std;
int main()
{
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    if (s1.length() < s2.length())
        cout<<"no";
        else
            cout<<"go";
    return 0;
}
