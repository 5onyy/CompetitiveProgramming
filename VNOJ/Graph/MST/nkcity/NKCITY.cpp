#include<bits/stdc++.h>

using namespace std;

#define pb push_back

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int n,m,ans;
vi par;

struct node{
    int u,v,w;
    node (int u,int v,int w)
    {
        this->u=u;
        this->v=v;
        this->w=w;
    }
};

bool cmp(const node &a, const node &b)
{
    return a.w<b.w;
}

vector <node> ed;

int root (int v)
{
    return par[v]<0 ? v: (par[v]=root(par[v]));
}

bool join(int x,int y)
{
    if ((x=root(x))==(y=root(y)))
        return false;
    if (par[y]<par[x])
        swap(x,y);
    par[x]+=par[y];
    par[y]=x;
    return true;
}

int main()
{
    freopen("NKCITY.INP","r",stdin);
    freopen("NKCITY.OUT","w",stdout);
    cin>>n>>m;
    par.assign(n+1,-1);
    for (int i=0;i<m;i++)
    {
        int t1,t2,w;
        cin>>t1>>t2>>w;
        ed.pb(node(t1,t2,w));
    }
    sort(ed.begin(),ed.end(),cmp);
    for (int i=0;i<m;i++)
    {
        if (join(ed[i].u,ed[i].v))
            ans=max(ans,ed[i].w);
    }
    cout<<ans;
}
