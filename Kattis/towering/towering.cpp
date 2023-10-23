#include<bits/stdc++.h>
using namespace std;
int a[6];
int h1,h2;
int main()
{
    for (int i=0;i<6;i++)
        cin>>a[i];
    sort(a,a+6);
    cin>>h1>>h2;
    do
    {
        if (a[0]+a[1]+a[2]==h1 && a[3]+a[4]+a[5]==h2)
        {
            cout<<a[2]<<" "<<a[1]<<" "<<a[0]<<" ";
            cout<<a[5]<<" "<<a[4]<<" "<<a[3];
            break;
        }
    }
    while (next_permutation(a,a+6));
    return 0;
}
