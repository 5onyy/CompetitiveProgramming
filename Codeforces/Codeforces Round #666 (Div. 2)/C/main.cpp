#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int n;
ll a[1000001];
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%lli",&a[i]);
    if (n==1)
    {
        printf("1 1\n");
        printf("%lli\n",a[1]);
        printf("1 1\n");
        printf("%lli\n",a[1]);
        printf("1 1\n");
        printf("%lli\n",-a[1]*3);
    }
    else
    {
        printf("1 1\n%lli \n",a[1]*(n-1));
        a[1]+=a[1]*(n-1);
        printf("2 %d\n",n);
        for (int i=2;i<=n;i++)
        {
            printf("%lli ",a[i]*(n-1));
            a[i]+=a[i]*(n-1);
        }
        printf("\n1 %d\n",n);
        for (int i=1;i<=n;i++)
        {
            printf("%lli ",-a[i]);
        }
    }
    return 0;
}
