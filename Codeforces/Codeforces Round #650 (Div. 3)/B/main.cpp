#include <bits/stdc++.h>

using namespace std;
int a,b;
int main()
{
    int tests;
    cin>>tests;
    while (tests--)
    {
        int n,dem=0;
        cin>>n;
        a=0,b=0;
        for (int i=0; i<n; i++)
        {
            int x;
            cin>>x;
            if ((x%2) != (i%2))
            {
                if (i%2==0)
                    a++;
                else b++;
            }
        }
        if (a==b) cout<<a<<endl;
        else cout<<-1<<endl;
//        bool bad=false;
//        for (int i=0; i<n; i++)
//        {
//            if (a[i]%2 != i%2)
//            {
//                bad=true;
//                break;
//            }
//        }
//        if (bad)    cout<<-1<<endl;
//        else cout<<0<<endl;
    }
    return 0;
}
