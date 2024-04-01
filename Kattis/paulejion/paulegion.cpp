#include<bits/stdc++.h>
using namespace std;
int n,p,q;
int main()
{
    cin>>n>>p>>q;
    int sum = p + q;

   if ((sum / n) % 2 == 0)
        cout << "paul" << endl;
   else
        cout << "opponent" << endl;

    return 0;
}
