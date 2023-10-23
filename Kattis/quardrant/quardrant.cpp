#include<bits/stdc++.h>
using namespace std;
long long x,y;
int main()
{
    cin>>x>>y;
    if ((x>0) && (y>0))
        cout<<1;
    else if ((x<0) && (y>0))
        cout<<2;
    else if ((x<0) && (y<0))
        cout<<3;
    else
        cout<<4;
    return 0;
}
