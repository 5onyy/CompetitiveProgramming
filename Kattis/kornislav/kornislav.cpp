#include<bits/stdc++.h>
#include<queue>
int x;
using namespace std;
int main()
{
    priority_queue<int> q;
    for (int i=0;i<4;i++)
    {
        cin>>x;
        q.push(x);
    }
    q.pop();
    int dai=q.top();
    q.pop();
    q.pop();
    int rong=q.top();
    cout<<dai*rong;
    return 0;
}
