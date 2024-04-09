#include <iostream>
#include <vector>

using namespace std;

int32_t main() {

	int n, k; cin >> n >> k;
	char symbol;
	vector a(n, vector<char>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];

		}

	}
	vector<vector<vector<long long>>>dp(k + 1, vector<vector<long long>>(n, vector<long long>(n)));
	// initialize...
	dp[0][0][0] = 1;
	for (int len = 1; len <= k; ++len) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (a[i][j] == '1') { // forbidden cell
					continue;
				}
				// we could reach this from the cell we have common border with
				if (i - 1 >= 0) 
					dp[len][i][j] += dp[len - 1][i - 1][j];
				if (i + 1 < n)
					dp[len][i][j] += dp[len - 1][i + 1][j];
				if (j - 1 >= 0)
					dp[len][i][j] += dp[len - 1][i][j - 1];
				if (j + 1 < n)
					dp[len][i][j] += dp[len - 1][i][j + 1];

			}

		}

	}
	cout << dp[k][n - 1][n - 1];

}