#include<bits/stdc++.h>
using namespace std;
long long R,C;
int main()
{
    cin>>R>>C;
    cout.precision(6);
    cout<<fixed<<(((R-C)*(R-C))/(double)(R*R))*100;
    return 0;
}
