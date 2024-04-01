#include <bits/stdc++.h>
using namespace std;
int main()
{
	int tests;
	cin >> tests;
	while (tests--) {
		long long a, b;
		cin >> a >> b;
		long long k = abs(a - b);
		long long x = k / 10;
		if (a != b && k % 10 == 0) cout << x << endl;
		else if (a != b) cout << x + 1 << endl;
		else cout << 0 << endl;
	}
    return 0;
}
