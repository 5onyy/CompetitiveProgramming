#include <bits/stdc++.h>

using namespace std;

int n;
bool check(int n)
{
    int d=0;
    while (n!=0)
    {
        int t=n%10;
        if (t!=0) d++;
        if (d==2) return 0;
        n/=10;
    }
    return 1;
}

int main()
{
    int tests;
    cin>>tests;
    while (tests--)
    {
        int ans=0;
        cin>>n;
        string s=to_string(n);
        int c=s.size()-1;
//        for (int i=1;i<=n;i++)
//            if (check(i))
//                cout<<i<<endl;
        cout<<9*c+(int)(s[0]-'0')<<endl;
    }
    return 0;
}
