#include<bits/stdc++.h>

using namespace std;

int n,p,x,y,z;
vector<int> par;

int root(int v)
{
    return par[v]<0 ? v: (par[v]=root(par[v]));
}

void join(int x,int y)
{
    if ((x=root(x))==(y=root(y)))
        return;
    if (par[y]<par[x])
        swap(x,y);
    par[x]+=par[y];
    par[y]=x;
}

int main()
{
    freopen("IOIBIN.INP","r",stdin);
    freopen("IOIBIN.OUT","w",stdout);
    cin>>p;
    par.assign(10001,-1);
    while (p--)
    {
        cin>>x>>y>>z;
        if (z==2)
        {
            if (root(x)==root(y))
                cout<<1<<endl;
            else cout<<0<<endl;
        }
        else join(x,y);
    }
}
