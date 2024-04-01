#include<bits/stdc++.h>
#include<string>
using namespace std;
string s;
int a[3];
int main()
{
    a[0]=1;
    cin>>s;
    for (int i=0;i<s.length();i++)
    {
        switch (s[i])
        {
            case 'A':swap(a[0],a[1]);
            break;
            case 'B':swap(a[1],a[2]);
            break;
            case 'C' :swap(a[0],a[2]);
            break;
        }
    }
    for (int i=0;i<3;i++)
    {
        if (a[i]==1)
            cout<<i+1;
    }
    return 0;
}
