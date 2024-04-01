#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

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

int main()
{
    freopen("T.INP","r",stdin);
    freopen("T.OUT","w",stdout);
    fastIO;
    string s;
    while (getline(cin,s) && s!="0")
    {
        ll l=sz(s);
        s=" "+s;
        vector<ll> f(sz(s),0);
        f[1]=f[0]=1;
        bool ok=true;
        if (s[1]=='0')  break;
        for (ll i=2;i<=l;i++)
        {
            if (s[i]=='0')  {f[i]=f[i-2]; continue;}
            ll tmp=(s[i-1]-'0')*10+(s[i]-'0');
            if (!tmp) {ok=false; break;}
            else if (tmp>=10 && tmp<=26)
                f[i]=f[i-1]+f[i-2];
            else f[i]=f[i-1];
        }
        if (ok) cout<<f[l]<<endl;
        else    cout<<0<<endl;
    }
}
