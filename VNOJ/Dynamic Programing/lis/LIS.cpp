#include <bits/stdc++.h>
#define inf INT_MAX
using namespace std;
int n;
int a[300001];
int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    vector <int> b(n+1,inf);
    int res=0;
    b[0]=-inf;
    for (int i=0;i<n;i++)
    {
        int idx=lower_bound(b.begin(),b.end(),a[i])-b.begin();
        b[idx]=a[i];
        res=max(res,idx);
    }
    printf("%d",res);
    return 0;
}
