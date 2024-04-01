#include<bits/stdc++.h>
using namespace std;
long long x,y,n;
int main()
{
    cin>>x>>y>>n;
    for (int i=1;i<=n;i++)
    {
        bool FizzBuzz= i%x==0 && i%y==0;
        bool Fizz= i%x==0;
        bool Buzz= i%y==0;
        if (FizzBuzz)
            cout<<"FizzBuzz"<<endl;
        else if (Fizz)
            cout<<"Fizz"<<endl;
        else if (Buzz)
            cout<<"Buzz"<<endl;
        else cout<<i<<endl;
    }
    return 0;
}
