#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tests;
    cin>>tests;
    while(tests--)
    {
        int r,g,b,w,chan=0;
        cin>>r>>g>>b>>w;
        //int sl=min(r,min(g,b));
        if (r%2==0) chan++;
        if (g%2==0) chan++;
        if (b%2==0) chan++;
        if (w%2==0) chan++;
        if (chan>=3 || (chan<2 && r>0 && g>0 && b>0))
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
            return 0;
}
