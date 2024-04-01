#include <iostream>
#include <fstream>
#include <cmath>

//std::ifstream iFs("294.inp");
std::ifstream iFs("input.inp");
std::ofstream oFs("input.out");
//std::ofstream oFs("294.out");

int prime[5500], p = 0;

void sieve() {
	int i, j;
	bool m[50005] = { };
	for (long long i = 2; i < 50000; ++i) {
		if (m[i] == 0) {
			prime[p++] = i;
			for (long long j = i * i; j < 50000; j += i) m[j] = 1;
		}
	}
}

int numDiv(int n) {
	int PF_idx = 0, PF = prime[PF_idx], ans = 1;

	while (PF * PF <= n) {
		int power = 0;
		while (n % PF == 0) n /= PF, power++;
		ans *= (power + 1);
		PF = prime[++PF_idx];
	}
	if (n != 1) ans *= 2;

	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); iFs.tie(0); std::cin.tie(0);

	if (iFs.fail()) return -1;

	sieve();

	int T; iFs >> T;
	while (T--) {
		long long L, U; iFs >> L >> U;
		int num_index = 0, num = 0;

		for (long long i = L; i <= U; ++i) {
			/*int dcount = 0;
			for (int j = 1; j <= std::sqrt(i); ++j) {
				if (i % j == 0) {
					dcount++;
					if (j < std::sqrt(i)) dcount++;
				}
			}*/

			int dcount = numDiv(i);

			if (dcount > num)
			{
				num_index = i;
				num = dcount;
			}
		}

		oFs << "Between " << L << " and " << U << ", " << num_index
			<< " has a maximum of " << num << " divisors.\n";
		//Between 'L' and 'U', 'num_index' has a maximum of 'num' divisors.
	}

	return 0;
}