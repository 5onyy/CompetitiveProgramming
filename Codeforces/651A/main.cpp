#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,d=0;
    cin>>a>>b;
    if (a-2<0 && b-2<0)
    {
        cout<<0; return 0;
    }
    while (true)
    {
        if (a>b)    {a-=2; b++;}
        else {b-=2; a++;}
        d++;
        if (a==0 || b==0)
            break;
    }
    cout<<d;
    return 0;
}
