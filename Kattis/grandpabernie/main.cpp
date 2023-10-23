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
#define int long long
#define double long double
#define log2(x)        log(x)/log(2.0)


typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int maxN=1001;
const int BASE=311;
const int MOD=1000000003;
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

unordered_map<string,vi> m;
int n,q;
unordered_set<string>dest;
signed main()
{
//    freopen(".INP","r",stdin);
//    freopen(".OUT","w",stdout);
    fastIO;
    cin>>n;
    while (n--)
    {
        string s;
        int year;
        cin>>s;
        cin>>year;
        dest.insert(s);
        if (m.count(s)<1)
        {
            vector<int> t;
            t.pb(year);
            m.insert({s,t});
        }
        else m[s].pb(year);
    }
    for (auto i: dest)
    {
        vector<int>& temp=m[i];
        sort(temp.begin(),temp.end());
    }
    cin>>q;
    while (q--)
    {
        string s;
        int t;
        cin>>s>>t;
        vector<int> & temp= m[s];
        cout<<temp[t-1]<<endl;
    }
}
