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

ll n;

bool ktsnt(ll n)
{
    if (n<2)
        return true;
    for (ll i=2;i<=sqrt(n);i++)
        if (n%i==0)
            return false;
    return true;
}

int main()
{
//    freopen(".INP","r",stdin);
//    freopen(".OUT","w",stdout);
    int tests;
    cin>>tests;
    while (tests--)
    {
        cin>>n;
        ll mod=n%4;
        if (n<12 && ktsnt(n))
            cout<<-1<<endl;
        else if (mod==1)
            cout<<(n-9)/4+1<<endl;
        else if (mod==2)
            cout<<(n-6)/4+1<<endl;
        else if (mod==3)
            cout<<(n-15)/4+2<<endl;
        else cout<<n/4<<endl;
    }
}
