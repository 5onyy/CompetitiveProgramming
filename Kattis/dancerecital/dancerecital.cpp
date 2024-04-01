#include<bits/stdc++.h>
using namespace std;
int n,d;
string a[100];
int main()
{
    cin>>n;
    for (int i=0; i<n; i++)
        cin>>a[i];
    sort(a,a+n);
    int i=-1;
    int res=2147483647;
    do
    {
        for (int i=1; i<n; i++)
        {
            for (int j=0; j<a[i].size(); j++)
            {
                if (binary_search(a[i-1].begin(),a[i-1].end(),a[i][j]))
                {
                    d++;
                }
            }
        }
        if (d<res)
            res=d;
            d=0;
    }
    while (next_permutation(a,a+n));
    cout<<res;
    return 0;
}
