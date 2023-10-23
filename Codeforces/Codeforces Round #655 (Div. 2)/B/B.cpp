#include <bits/stdc++.h>

using namespace std;
int t,n;
bool ktsnt(int n)
{
    if (n<2)    return false;
    for (int i=2;i<=trunc(sqrt(n));++i)
    {
        if (n%i==0) return false;
    }
    return true;
}
int main()
{
    cin>>t;
    while (t--)
    {
        int ans=999999999;
        scanf("%d",&n);
        if (!(n&1))
            printf("%d %d \n",n/2,n/2);
        else
        {
            if (ktsnt(n))
                printf("1 %d \n",n-1);
            else
            {
                for (int i=2;i<=n;i++)
                {
                    if (n%i==0)
                        {
                            printf("%d %d \n",n/i,n-n/i);
                            break;
                        }
                }
            }
        }
    }
    return 0;
}
