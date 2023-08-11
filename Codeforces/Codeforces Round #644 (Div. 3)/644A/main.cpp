#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tests;
    cin>>tests;
    while (tests--)
    {
        int a,b;
        cin>>a>>b;
        if (a<b) swap(a,b);
        if (b*2>=a) cout<<b*b*4<<endl;
        else cout<<a*a<<endl;
    }
    return 0;
}
