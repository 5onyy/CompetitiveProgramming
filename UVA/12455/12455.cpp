#include <bits/stdc++.h>
#define maxN 1010

using namespace std;

int main()
{
	freopen("12455.INP","r",stdin);
    freopen("12455.OUT","w",stdout);
	int test;
	cin >> test;
	while (test--)
	{
		int n, m, a[maxN], sum;
		cin >> m >> n;
		for (int i = 0;i < n;i++) cin >> a[i];

		for (int i = 0; i < (1 << n); i++)
		{
			sum = 0;
			for (int j = 0; j < n; j++)
				if (i & (1 << j))
					sum += a[j];
			if (sum == m) break;
		}

		if (sum == m) cout << "YES"; else cout << "NO";
		cout << endl;
	}



	return 0;
}
