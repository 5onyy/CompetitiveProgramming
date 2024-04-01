#include <bits/stdc++.h>

using namespace std;
int a[1000000],lc=0;
int tong(int l,int r)
{
    int tmp=0;
    for (int i=l;i<=r;i++)
        tmp+=a[i];
    return tmp;
}
int main()
{
    //freopen("TEST.INP","r",stdin);
    int tests;
    cin>>tests;
    while (tests--)
    {
        memset(a,0,sizeof a);
        int n,k,z;
        cin>>n>>k>>z;
        for (int i=1;i<=n;i++)
            cin>>a[i];
        int sum=a[1];
        int vt=1;
        for (int t=0;t<k;t++)
        {
            if (tong(vt+1,vt+k-t)<tong(vt-(k-t),vt-1) && z>0)
            {
                z--;
                vt--;
            }
            else if (tong(vt+1,vt+k-t)>tong(vt-(k-t),vt-1))
                vt++;
            else vt++;
            sum+=a[vt];
        }
        cout<<sum<<endl;
    }
    return 0;
}
