#include <bits/stdc++.h>

using namespace std;
int sl5,max5,sl0;
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if (x==0) sl0++;
        else {
            sl5++;
            if (sl5%9==0)
                max5=sl5;
        }
    }
    if (max5==0 && sl0>=1)    cout<<0;
    else if (sl0==0 && max5==0)    cout<<-1;
    else if (sl0==0) cout<<-1;
    else{
    for (int i=1;i<=max5;i++)
        cout<<5;
    for (int i=1;i<=sl0;i++)
        cout<<0;
    }
    return 0;
}
