#include <bits/stdc++.h>

using namespace std;

void solve(string s)
{
    map<char,int> mp;
    for (int i=0;i<s.size();i++)
        mp[s[i]]+=1;
    int flag=0;
    char tmp=' ';
    for (map<char,int>::iterator itr=mp.begin();itr!=mp.end();itr++)
    {
        if (itr->second %2 !=0)
            {flag++;  tmp=itr->first;}
        if (flag>1)
        {
            cout<<"NO SOLUTION";
            return;
        }
    }
    int n=s.size();
    string ans(s.size(),' ');
    if (flag==1)
    {
        ans[n/2]=tmp;
        for (int i=1;i<=(mp[tmp]-1)/2;i++)
            ans[n/2-i]=ans[n/2+i]=tmp;
        mp.erase(mp.find(tmp));
    }
    int vt=0;
    for (map<char,int>::iterator itr=mp.begin();itr!=mp.end();itr++)
    {
        ans[n-vt-1]=ans[vt]=itr->first;
        for (int i=1;i<itr->second/2;i++)
            ans[vt+i]=ans[n-vt-1-i]=itr->first;
        vt+=itr->second/2;
    }
    cout<<ans;
}

int main()
{
    string s;
    cin>>s;
    solve(s);
    return 0;
}
