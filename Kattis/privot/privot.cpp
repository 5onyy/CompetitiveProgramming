#include<bits/stdc++.h>
using namespace std;
int max1[100001],min1[100001],a[100001];
int n;
int main()
{
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    max1[0]=0;
    int l=a[0];
    for (int i=1;i<n;i++)
    {
        if (a[i]<l)
            max1[i]=l;
        else
        {
            max1[i]=l;
            l=a[i];
        }
    }
    min1[n-1]=a[n-1]+1;
    l=a[n-1];
        for (int i=n-2;i>=0;i--)
    {
        if (a[i]>l)
            min1[i]=l;
        else
        {
            min1[i]=l;
            l=a[i];
        }
    }
    int d=0;
    for (int i=0;i<n;i++)
    {
        if (a[i]>max1[i]&&a[i]<min1[i])
            d++;
    }
    cout<<d;
    return 0;
}
