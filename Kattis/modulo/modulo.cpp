#include<bits/stdc++.h>
using namespace std;
bool a[42];
int x,d=0;
int main()
{
    for (int i=0; i<10; i++)
    {
        cin>>x;
        if (!a[x%42])
        {

            d++;
            a[x%42]=true;
        }
    }
    cout<<d;
    return 0;
}
