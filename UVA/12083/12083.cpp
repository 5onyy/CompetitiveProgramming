#include<bits/stdc++.h>

using namespace std;

#define fastIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define inf 999999999
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> ii;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ii> vii;

const ll BASE=311;
const ll MOD=1000000003;
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

int nu,nam,n;
vi vis,match;
vector<vi> a;

int Aug(int l)   // return 1 if an augmenting path is found
{
    if (vis[l])
        return 0; // return 0 otherwise
    vis[l] = 1;
    for (int j = 0; j < (int)a[l].size(); j++)
    {
        int r = a[l][j]; // edge weight not needed -> vector<vi> a
        if (match[r] == -1 || Aug(match[r]))
        {
            match[r] = l;
            return 1; // found 1 matching
        }
    }
    return 0; // no matching
}

struct node{
    int hi;
    char sex;
    string mus,hob;
    node(int hi, char sex, string mus, string hob)
    {
        this->hi=hi;
        this->sex=sex;
        this->mus=mus;
        this->hob=hob;
    }
};

int main()
{
    freopen("12083.INP","r",stdin);
    freopen("12083.OUT","w",stdout);
    int tests;
    cin>>tests;
    while (tests--)
    {
        a.clear();
        nam=0,nu=0;
        vector<node> l,r;
        cin>>n;
        for (int i=0;i<n;i++)
        {
            int cao;
            char gt;
            string nhac,st;
            cin>>cao>>gt>>nhac>>st;
            nam=nam+ ((gt=='M') ? 1 : 0);
            nu=nu+ ((gt=='F') ? 1 : 0);
            if (gt=='M') l.pb(node(cao,gt,nhac,st));
            else if (gt=='F') r.pb(node(cao,gt,nhac,st));
        }
        a.assign(nam+nu,vi());
        for (int i=0;i<sz(l);i++)
        {
            for (int j=0;j<sz(r);j++)
            {
                if (abs(l[i].hi-r[j].hi)<=40 && l[i].mus==r[j].mus &&   l[i].hob != r[j].hob)
                    a[i].pb(j+nam),   a[j+nam].pb(i);
            }
        }
        int MCBM = 0;
        match.assign(nu+nam, -1); // V is the number of vertices in bipartite graph
        for (int l = 0; l < nu; l++)   // n = size of the left set
        {
            vis.assign(nu+nam, 0); // reset before each recursion
            MCBM += Aug(l+nam);
        }
        cout<<n-MCBM<<endl;
    }
    return 0;
}
