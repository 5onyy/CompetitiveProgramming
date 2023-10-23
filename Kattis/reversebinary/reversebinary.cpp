#include<bits/stdc++.h>
using namespace std;
unsigned int n,s;
int y=-1;
int a[33];
void chuyen(int n)
{
    while (n!=0)
    {
        y++;
        a[y]=n%2;
        n=n/2;
    }
}
int main()
{
    cin>>n;
    chuyen(n);
    for (int i=y;i>=0;i--)
    {
        if (a[i])
            s=s+pow(2,abs(i-y));
    }
    cout<<s;
    return 0;
}
