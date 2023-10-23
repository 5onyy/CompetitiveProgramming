#include <iostream>

using namespace std;

long long n,ans;

int main()
{
    cin>>n;
    for (long long i=5;n/i>=1;i*=5)
    {
        ans+=(n/i);
    }
    cout<<ans;
    return 0;
}
