#include<bits/stdc++.h>
#include<string>
using namespace std;
int n;
string a[21];
int main()
{
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    bool D=false;
    bool I=false;
    bool N=false;
    for (int i=0; i<n-1; i++)
    {
        if (a[i]>=a[i+1])
        {
            D=true;
        }
        else if (a[i]<a[i+1])
        {
            I=true;
        }
        if (D==true && I==true)
            N=true;
    }
    if (N==true)
        cout<<"NEITHER";
    else if (I==true)
        cout<<"INCREASING";
    else
        cout<<"DECREASING";
    return 0;
}
