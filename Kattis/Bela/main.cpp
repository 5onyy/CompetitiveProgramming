#include <bits/stdc++.h>
using namespace std;
char c;
string s;
int  dom[1001],nondom[1001],ans=0,n;
int main()
{
    dom['A']=11;  dom['K']=4;   dom['Q']=3; dom['J']=20;    dom['T']=10;    dom['9']=14;    dom['8']=dom['7']=0;
    nondom['A']=11;  nondom['K']=4;   nondom['Q']=3; nondom['J']=2;    nondom['T']=10;    nondom['9']=dom['8']=dom['7']=0;
    cin>>n>>c;
    for (int i=0;i<n*4;i++)
    {
        cin>>s;
        if (s[1]==c)
            ans+=dom[s[0]];
        else ans+=nondom[s[0]];
    }
    cout<<ans;
    return 0;
}
