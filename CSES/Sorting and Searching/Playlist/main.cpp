#include<bits/stdc++.h>

using namespace std;

#define fastIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mp make_pair
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

int n,j,cur,ans,x;
map<int,bool> m;
vi a;

int main()
{
//    freopen(".INP","r",stdin);
//    freopen(".OUT","w",stdout);
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>x;     a.pb(x);
        if (m.find(x)==m.end()|| m[x]==0)
        {
            cur++; m[x]=1; ans=max(ans,cur);
        }
        else
        {
            while (a[j]!=x)
            {
                m[a[j]]=0;
                j++;
            }
            cur=i-j;
            j++;
        }
    }
    cout<<ans;
}
