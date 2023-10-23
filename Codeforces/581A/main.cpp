#include <iostream>

using namespace std;

int main()
{
    int a,b,ans=0;
    cin>>a>>b;
    ans=min(a,b);
    a-=ans;
    b-=ans;
    cout<<ans<<" "<<a/2+b/2;
    return 0;
}
