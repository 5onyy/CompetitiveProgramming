#include<bits/stdc++.h>
using namespace std;
int s=0,n,f1,f2;
int a[100];
bool check()
{
    for (f1=0; f1<8; f1++)
    {
        for (f2=f1+1; f2<9; f2++)
        {
            if (s-a[f1]-a[f2]==100)
                return true;
        }
    }
}
int main()
{
    for (int i=0; i<9; i++)
    {
        cin>>a[i];
        s+=a[i];
    }
    if (check())
    {
        for (int i=0; i<9; i++)
        {
            if (i!=f1 && i!=f2)
                cout<<a[i]<<" "<<endl;
        }
    }
    return 0;
}
