#include<bits/stdc++.h>
using namespace std;
int a[51];
int main()
{
    int n,w,h,x;
    cin>>n>>w>>h;
    for (int i=0;i<n;i++)
    {
        cin>>x;
        if (x<=h||x<=(double)(sqrt(w*w+h*h)))
            {
                a[i]=1;
            }
        else a[i]=0;
    }
    for (int i=0;i<n;i++)
    {
        if (a[i])
            cout<<"DA"<<endl;
        else cout<<"NE"<<endl;
    }
}
