#include<bits/stdc++.h>
#define fastIO ios::sync_with_stdio(FALSE), cin.tie(NULL), cout.tie(NULL)
using namespace std;
long long n,a,b,c;
long long mins(long long a, long long b, long long c)
{
    return min(a,min(b,c));
}
int main()
{
    freopen("10882.INP","r",stdin);
    freopen("10882.OUT","w",stdout);
    cin>>n;
    for (int t=1;t<=n;t++)
    {
        cin>>a>>b>>c;
        int high= mins(a,b,c);
        int low =(a+b+c-99)/2;
        if(a+b+c <=100)
        {
			low = 0;
		}
        if (low<0 || low>high)
            cout<<"Case #"<<t<<": "<<"The record are faulty."<<endl;
        else
            cout<<"Case #"<<t<<": "<<"Between "<<low<<" and "<<high<<" times."<<endl;
    }
    return 0;
}
