#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x,y,z,t;
    cin>>x>>y>>z>>t;
    int a[4]={x,y,z,t};
    sort(a,a+4);
    x=a[0];
    y=a[1];
    z=a[2];
    t=a[3];
    int ans1=x+y-t;
    int ans2=x+z-t;
    int ans3=y+z-t;
    printf("%d %d %d",ans1,ans2,ans3);
    return 0;
}
