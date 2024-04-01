#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef unsigned long long ull;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

int n,l;
int s[6001],a[6001],f[6001];

void solve()
{
    f[1]=l-a[1];
    for (int i=2;i<=n;i++)
    {
        f[i]=INT_MAX;
        for (int j=i;j>=1;j--)
        {
            if (s[i]-s[j-1]>l)
                break;
            else
                f[i]=min(max(f[j-1],l-(s[i]-s[j-1])),f[i]);
        }
    }
}
int main()
{
    freopen("PTRANG.INP","r",stdin);
    freopen("PTRANG.OUT","w",stdout);
    cin>>n>>l;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];           ///prefix sum
    }
    solve();
//    for (int i=1;i<=n;i++)
//        cout<<f[i]<<endl;
    cout<<f[n];
    return 0;
}
