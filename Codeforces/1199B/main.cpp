#include <bits/stdc++.h>

using namespace std;

int main()
{
    double l,h;
    cin>>h>>l;
    double ans=(l*l-h*h)/(2.0*h);
    cout<<fixed<<setprecision(13)<<ans;
    return 0;
}
