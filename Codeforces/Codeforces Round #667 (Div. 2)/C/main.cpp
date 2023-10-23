#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tests;
    cin>>tests;
    while (tests--)
    {
        int n, x, y;
        cin >> n >> x >> y;
        if (n == 2)
        {
            cout << x << " " << y << endl;
            continue;
        }
        vector<int> a;
        for (int i=1; i<=y-x; i++)
        {
            if ((y - x) % i != 0)
                continue;
            int c = (y - x) / i - 1;
            if (c + 2 > n) continue;
            int l = x;
            while (a.size() < n && l <= y )
            {
                a.push_back(l);
                l += i;
            }
            if (x - i >= 1)
                while (a.size() < n && x - i > 0)
                {
                    x -= i;
                    a.push_back(x);
                }
            if (y + i <= 1e9)
                while (a.size() < n && y + i <= 1e9)
                {
                    y += i;
                    a.push_back(y);
                }
        }
        for (int i=0; i<n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
}


