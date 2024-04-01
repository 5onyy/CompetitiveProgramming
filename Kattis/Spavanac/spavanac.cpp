#include<bits/stdc++.h>
using namespace std;
int h,m;
int main()
{
    cin>>h>>m;
    if (h==0)
        h=24;
    if (m>=45)
        cout<<h<<" "<<m-45;
    else
        cout<<h-1<<" "<<m+15;
    return 0;
}
