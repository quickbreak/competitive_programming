#include <iostream>
#include <vector>


using namespace std;


int main() {
	int n, m; cin >> n >> m;
	vector<vector<int>>a(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	vector<vector<int>>dp(n, vector<int>(m));
	dp[0][0] = a[0][0];
	for (int j = 1; j < m; ++j) {
		dp[0][j] = dp[0][j - 1] + a[0][j];
	}
	for (int i = 1; i < n; ++i) {
		dp[i][0] = dp[i - 1][0] + a[i][0];
	}

	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < m; ++j) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
		}
	}

	cout << dp[n - 1][m - 1] << '\n';
	int i = n - 1, j = m - 1;
	string res = "";
	while (i > 0 && j > 0) {
		if (dp[i - 1][j] > dp[i][j - 1]) {
			res = "D " + res;
			--i;
		} else {
			res = "R " + res;
			--j;
		}	
	}
	while (i > 0) {
		res = "D " + res;
		--i;
	}
	while (j > 0) {
		res = "R " + res;
		--j;
	}
	cout << res;
}
