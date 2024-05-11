#include <iostream>
#include <vector>

using namespace std;

int32_t main() {
	int n; cin >> n;
	vector a(n, 0), dp(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	reverse(a.begin(), a.end());
	int k; cin >> k;
	dp[0] = a[0];
	for (int i = 1; i < min(k, n); ++i) {
		dp[i] = dp[i - 1] + a[i];
	}
	int next_cnt = 0, summa = 0;
	for (int i = k; i < n; ++i) {
		summa = 0;
		for (int u = i; u > max(i - next_cnt - 1, -1); --u) {
			summa += a[u];
		}
		for (int j = next_cnt; j <= k; ++j) {
			if (i - j < 0)
				break;
			summa += a[i - j + 1];
			dp[i] = max(dp[i], summa - dp[i - j]);
		}
	}
	cout << dp[n - 1];

}