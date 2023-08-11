#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tests;
    cin>>tests;
    while (tests--)
    {
        int n,d,tmp=-1;
        string num;
        cin>>n>>d;
        cin>>num;
        if (d==0)
            cout<<num<<d;
        else
        {
            for (int i=0;i<n;i++)
                tmp=max(tmp,(int)num[i]-(int)'0');
            if (tmp==d)
                cout<<d<<num;
            else{
                for (int i=0;i<n;i++)
                {
                    if (num[i]>k)
                        vt=k;
                }
            }

        }
    }
    return 0;
}
