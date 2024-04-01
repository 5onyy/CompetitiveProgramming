#include <bits/stdc++.h>
using namespace std;
string a,b;
int main()
{
    cin>>a>>b;
        int n=a.size();
        while (--n>=0)
        {
            if (a[n]>b[n])
                {
                for (int i=a.size()-1;i>=0;i--) cout<<a[i];
                break;
            }
            if (a[n]<b[n])
            {
                for (int i=b.size()-1;i>=0;i--) cout<<b[i];
                break;
            }
        }
    return 0;
}
