#include<bits/stdc++.h>
#include<string>
#define fastIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;
long long c[60][60],t;
long long coefficent(int n, int k)
{

    if (n == k || k == 0)
        return 1;

    long long & val = c[n][k];

    if (val == 0)
    {
        val = coefficent(n - 1, k - 1) + coefficent(n - 1, k);
    }

    return val;
}
int main()
{
    freopen("11955.INP","r",stdin);
    freopen("11955.OUT","w",stdout);
    cin>>t;
    for (long long temp=1;temp<=t;temp++)
    {
        string s,word1,word2;

        cin>>s;

        int pos1=s.find("+");

        word1=s.substr(1,pos1-1);

        int pos2=s.find(")");
        pos1++;

        word2=s.substr(pos1,pos2-pos1);

        pos2+=2;

        string number=s.substr(s.size()-pos2);
        int k = atoi(s.substr(pos2).c_str());

        cout<<"Case "<<temp<<": "<<word1;

        ///Special case
        if (k==1)
        {
            cout<<'+'<<word2<<endl;
            continue;
        }
        cout<<'^'<<k;
        for (int i = 1; i < k; ++i)
        {
            cout << '+' << coefficent(k, k - i) << '*'<< word1;
            if (k - i != 1)
                cout << '^' << (k - i);
            cout << '*' << word2;
            if (i != 1)
                cout << '^' << i;
        }
        cout << '+' << word2 << '^' << k <<endl;

    }
    return 0;
}
