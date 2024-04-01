#include <bits/stdc++.h>

using namespace std;
int n;
bool square=false,rec1,rec2;
int d[1000000];
int main()
{
    freopen("T.INP","r",stdin);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        d[x]++;
    }
    for (int i=1;i<=100000;i++)
    {
        if
    }
    int quest;
    cin>>quest;
    while (quest--)
    {
        int x;
        char c;
        cin>>c;
        cin>>x;
        if (c=='-') d[x]--;
        if (c=='+') d[x]++;
        if (d[x]==4)    square=true;
        if (d[x]==8)    square=rec1=rec2=true;
        if (d[x]==2 && square==false)
        {
            if (rec1==false && rec2==false)
                rec1=true;
            else rec2=true;
        }
        else if (square==true && d[x]-4==2)
        {
            if (rec1==false && rec2==false)
                rec1=true;
            else rec2=true;
        }
        if (rec1==true && rec2==true && square==true)
        {
            cout<<"YES"<<endl;
            rec1=rec2=square=false;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}
