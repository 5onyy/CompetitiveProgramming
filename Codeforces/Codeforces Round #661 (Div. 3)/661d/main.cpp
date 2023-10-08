#include <bits/stdc++.h>

using namespace std;
string s;
int ans=0;
int c[2],vt[1000000];
int tmp[1005][1005];
int main()
{

    int tests;
    cin>>tests;
    while (tests--)
    {
        int n;
        memset(c,0,sizeof c);
        cin>>n;
        cin>>s;
        memset(vt,-1,sizeof vt);
        ans=0;
        while (true)
        {
            ans++;
            vector <int> d[2];
            for (int i=0;i<2;i++)
            {
                int vt1=0;
                for (int j=0;j<n;j++)
                {
                    if (s[j]==tmp[i][vt1] && vt[i]==-1)
                    {
                        d[i].push_back(j);
                        vt1=(vt1+1) %2;
                    }
                }
            }
            if (d[0].size() > d[1].size())
            {
                for (int i=0;i<d[0].size();i++)
                    vt[d[0][i]]=ans;
            }
            else
            {
                for (int i=0;i <d[1].size();i++)
                    vt[d[1][i]]=ans;
            }
            for (int i=0;i<n;i++)
            {
                if (vt[i]==-1)  c[s[i]-'0']++;
            }
            if (c[0]==0 || c[1]==0) break;
        }
        for (int i=0;i<n;i++)
        {
            if (vt[i]==-1)  vt[i]=++ans;
        }
        cout<<ans<<endl;
        for (int i=0;i<n;i++) cout<<vt[i]<<" ";
        cout<<endl;
    }
    return 0;
}
