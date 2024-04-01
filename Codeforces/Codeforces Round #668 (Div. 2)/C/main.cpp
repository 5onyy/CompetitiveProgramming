#include <bits/stdc++.h>

using namespace std;
int main()
{
    freopen("T.INP","r",stdin);
    int tests;
    cin>>tests;
    while (tests--)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<int> cnt(2,0);
        bool bad=false;
        for (int i=0;i<k;i++)
        {
            int tmp=-1;
            for (int j=i;j<n;j+=k)
            {
                if (s[j]!='?')
                {
                    if (tmp!=-1 && s[j]-'0' != tmp)
                    {
                        bad=true;
                        break;
                    }
                    tmp=s[j]-'0';
                }
            }
            if (tmp!=-1)
                cnt[tmp]++;
        }
        if (cnt[1]>k/2 || cnt[0]>k/2)
            bad=true;
        if (bad)    cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        //cout<<endl;
    }
    return 0;
}
