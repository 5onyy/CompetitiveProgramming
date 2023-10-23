#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tests;
    cin>>tests;
    while (tests--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        if (s.find('L')==string::npos || s.find('R')==string::npos)
            cout<<-1<<endl;
        else {
            bool f=0;
            int k=s.find('R');
            for (int i=k+1;i<s.size();i++)
            {
                if (s[i]=='L')
                {
                    cout<<0<<endl;
                    f=1;
                    break;
                }

            }
            if (f==0)
            {
                for (int i=0;i<k;i++)
                    if (s[i]=='L')
                    {
                        cout<<k-i<<endl;
                        break;
                    }
            }
        }
    }
    return 0;
}
