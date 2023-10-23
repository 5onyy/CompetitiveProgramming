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
#define int unsigned long long
#define double long double
#define log2(x)        log(x)/log(2.0)
#define hardio(x)      freopen(x".inp","r",stdin), freopen(x".out","w",stdout);
#define rall(x)        x.rbegin(),x.rend()

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int maxN=1001;
const int BASE=311;
const int N=1e5+5;
const int MOD=1000000003;

int n;
int mod=1e9+7;

int solve(int n)
{
    if (n==2)  return(7*2022%mod);
    int mid=n/2+1,u1=mid,un=mid*n,ans=0 ;
    int s1=(u1+un)*n/2;
//    cout<<s1<<endl;
    ans=((ans+s1))%mod;
    int s2=(1+mid-1)*(mid-1)/2;
//    cout<<s2<<endl;
    ans=((ans+s2))%mod;
    u1=un+n;
    int s3=(u1+n*n)*((n*n-u1)/n+1)/2;
    ans=((ans+s3))%mod;
//    cout<<s3<<endl;
    return (ans*2022)%mod;
}

signed main()
{
    int tests;
    cin>>tests;
    while (tests--)
    {
        cin>>n;
        cout<<solve(n)<<endl;
    }
    fastIO;

}
