#include <iostream>

using namespace std;
int fgcd(int a, int b) {while(b) swap(b, a %= b); return a;}

bool prime(int n)
{
    if (n<2)    return 0;
    for (int i=2; i*i<=n; i++)    if (n%i==0) return 0;
    return 1;
}

int main()
{
    int test;
    cin>>test;
    while (test--)
    {
        int l,r;
        cin>>l>>r;
        bool kt=0;
        if (l==1 && r==4)   cout<<2<<' '<<2<<'\n';
        else if ((l==1 && r==3) || (l==2 && r==3) || (l==1 && r==2)) cout<<"-1\n";
        else if (l==r)
        {
            if (l&1) cout<<(l-1)/2-2<<' '<<l-((l-1)/2-2)<<'\n';
            //if (!kt) cout<<-1<<'\n';
        }
        else if (l&1) cout<<l-1<<' '<<2<<'\n';
        else cout<<l-2<<' '<<2<<'\n';
    }
    return 0;
}
