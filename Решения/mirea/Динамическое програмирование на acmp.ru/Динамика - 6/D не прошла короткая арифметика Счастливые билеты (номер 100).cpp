#include <iostream>
#include <vector>
#include <cassert>
#include <iomanip>

using namespace std;

using ll = long double;

int32_t main() {
	int n; cin >> n;
	assert(n >= 2);

	vector cnt_sum(51, vector<ll>(901)); // количество i-значных чисел, сумма которых == j
	// small_initialize
	for (ll digit = 0; digit < 10; ++digit) {
		cnt_sum[1][digit] = 1;
	}
	// small_dp
	for (ll len = 2; len < 51; ++len) { // length of number
		for (ll summa = 0; summa <= 900; ++summa) { // previous sum
			for (ll digit = 0; digit <= 9; ++digit) { // next(current) digit
				if (summa + digit > 900)
					break;
				cnt_sum[len][summa + digit] += cnt_sum[len - 1][summa];
			}

		}

	}

	vector lucky_dp(101, vector<ll>(901));
	// initialize

	// dp
	/*for (int len = 1; len <= 50; ++len) {
		for (ll summa = 0; summa <= 900; ++summa) {
			for (ll digit = 0; digit <= 9; ++digit) {
				if (summa + digit > 900)
					break;
				lucky_dp[2 * len][summa + digit] += cnt_sum[len][summa + digit];
			}
		}
	}*/
	for (int len = 1; len <= 50; ++len) {
		for (ll summa = 0; summa <= 450; ++summa) {
			lucky_dp[2 * len][2*summa] = cnt_sum[len][summa] * cnt_sum[len][summa];
		}
	}
	ll ans = 0;
	for (int summa = 0; summa <= 900; ++summa)
		ans += lucky_dp[n][summa];
	
	printf("%Lf", ans);
}
/*
4
670

6
55252

12
39581170420*/