#include <bits/stdc++.h>

using namespace std;
int s1,s2,s3;
int c[200];
int main()
{
    cin>>s1>>s2>>s3;
    for (int i=1;i<=s1;i++)
    {
        for (int j=1;j<=s2;j++)
        {
            for (int k=1;k<=s3;k++)
                c[i+j+k]++;
        }
    }
    int res=0,ans;
    for (int i=1;i<200;i++)
    {
        if (res<c[i])
        {
            res=c[i];   ans=i;
        }
    }
    cout<<ans;
    return 0;
}
