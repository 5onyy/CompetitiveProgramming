#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a1,a2,b1,b2;
    cin>>a1>>b1>>a2>>b2;
    int s1=a1+b1+a2+b2;
    cin>>a1>>b1>>a2>>b2;
    int s2=a1+b1+a2+b2;
    if (s1>s2)
        cout<<"Gunnar";
    else if (s1==s2)
        cout<<"Tie";
    else cout<<"Emma";
    return 0;
}
