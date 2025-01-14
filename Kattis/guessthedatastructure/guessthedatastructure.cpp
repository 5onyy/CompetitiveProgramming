#include<bits/stdc++.h>

using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);
    int n;
    int command, val;
    while (cin >> n)
    {
        stack<int> S;
        queue<int> Q;
        priority_queue<int> PQ;

        // -1 for impossible, the order is s, q, pq;
        vector<int> judge{0, 0, 0};
        while (n--)
        {
            cin >> command >> val;
            if (command == 1)
            {
                if (judge[0] != -1)
                {
                    S.push(val);
                }
                if (judge[1] != -1)
                {
                    Q.push(val);
                }
                if (judge[2] != -1)
                {
                    PQ.push(val);
                }
            }
            else
            {
                //handle 0 elements
                if (S.empty())
                {
                    judge[0] = -1;
                }
                if (Q.empty())
                {
                    judge[1] = -1;
                }
                if (PQ.empty())
                {
                    judge[2] = -1;
                }

                //handle non 0 elements
                if (judge[0] != -1)
                {
                    if (S.top() == val)
                    {
                        S.pop();
                    }
                    else
                    {
                        judge[0] = -1;
                    }
                }
                if (judge[1] != -1)
                {
                    if (Q.front() == val)
                    {
                        Q.pop();
                    }
                    else
                    {
                        judge[1] = -1;
                    }
                }
                if (judge[2] != -1)
                {
                    if (PQ.top() == val)
                    {
                        PQ.pop();
                    }
                    else
                    {
                        judge[2] = -1;
                    }
                }
            }
        }
        int negativeCnt = 0;
        for (int i=0; i<judge.size(); i++)
        {
            if (judge[i]==0)
                negativeCnt++;
        }
        if (negativeCnt ==0)
        {
            cout << "impossible" << endl;
        }
        else if (negativeCnt >1)
        {
            cout << "not sure" << endl;
        }
        else
        {
            if (judge[0] == 0)
            {
                cout << "stack" << endl;
            }
            else if (judge[1] == 0)
            {
                cout << "queue" << endl;
            }
            else
            {
                cout << "priority queue" << endl;
            }
        }
    }
    return 0;
}
