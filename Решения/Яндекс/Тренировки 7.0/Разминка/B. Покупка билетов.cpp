#include <iostream>
#include <vector>


using namespace std;


int main() {
	int n; cin >> n;
	vector<vector<int>>a(n, vector<int>(4));
	for (auto& v : a)
		cin >> v[1] >> v[2] >> v[3];
	vector<int>dp(n);
	if (n >= 1) {
		dp[0] = a[0][1];
	}
	if (n >= 2) {
		dp[1] = min(dp[0] + a[1][1], a[0][2]);
	}
	if (n >= 3) {
		dp[2] = min(dp[1] + a[2][1], dp[0] + a[1][2]);
		dp[2] = min(dp[2], a[0][3]);
	}
	for (int i = 3; i < n; ++i) {
		dp[i] = min(dp[i - 1] + a[i][1], dp[i - 2] + a[i - 1][2]);
		dp[i] = min(dp[i], dp[i - 3] + a[i - 2][3]);
	}
	cout << dp[n - 1];
}
