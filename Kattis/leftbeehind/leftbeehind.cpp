#include<bits/stdc++.h>
using namespace std;
int a[20];
int x,y,n=-1;
int main()
{
    while (cin>>x>>y)
    {
        if (x!=0||y!=0)
        {
            if (x+y==13)
            {
                n++;
                a[n]=4;
            }
            else if (x<y)
            {
                n++;
                a[n]=2;
            }
            else if (x>y)
            {
                n++;
                a[n]=1;
            }
            else
            {
                n++;
                a[n]=3;
            }
        }
        else
            break;
    }
    for (int i=0; i<=n; i++)
    {
        switch(a[i])
        {
                case 4:
            cout<<"Never speak again."<<endl;
            break;
        case 2:
            cout<<"Left beehind."<<endl;
            break;
        case 1:
            cout<<"To the convention."<<endl;
            break;
        case 3:
            cout<<"Undecided."<<endl;
            break;
        }
    }
    return 0;
}
