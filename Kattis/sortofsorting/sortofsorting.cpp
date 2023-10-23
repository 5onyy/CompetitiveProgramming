#include<bits/stdc++.h>
using namespace std;
int n;
bool cmp(string x,string y)
{
    if (x[0]==y[0])
    {
        return (x[1]<y[1]);
    }
    else return (x[0]<y[0]);
}
int main()
{
    while (cin>>n)
    {
        cout<<endl;
        if (n!=0)
        {
            string a[201];
            for (int i=0;i<n;i++)
            {
                cin>>a[i];
            }
            stable_sort(a,a+n,cmp);
            for(int i=0;i<n;i++)
                cout<<a[i]<<endl;
        }
        else break;
    }
    return 0;
}
