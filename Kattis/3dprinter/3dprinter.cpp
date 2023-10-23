#include<bits/stdc++.h>
using namespace std;
int n,d;
int main()
{
    cin>>n;
    while (pow(2,d)<n)
    {
        d++;
    }
    if (pow(2,d)<n)
        cout<< d+2;
    else cout<<d+1;
    return 0;
}
