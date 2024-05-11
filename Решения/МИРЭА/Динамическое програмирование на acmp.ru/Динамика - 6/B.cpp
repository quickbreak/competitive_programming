#include <iostream>
#include <vector>

using namespace std;

int32_t main() {

	int n, m; cin >> n >> m;
	vector dp(n+1, vector<pair<int, int>>(m+1));
	vector max_left(n + 1, vector<int>(m + 1));
	vector max_right(n + 1, vector<int>(m + 1));
	char x;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> x;
			if (x == '0') {
				dp[i][j] = { 0, 0 };
				continue;
			}
			max_left[i][j] = max_left[i][j - 1] + 1;
			max_right[i][j] = max_right[i][j - 1] + 1;
			ans = max()
			dp[i][j].first = min(dp[i - 1][j - 1].first + 1, dp[i - 1][j].first + 1);
			dp[i][j].second = min(dp[i - 1][j - 1].second + 1, dp[i][j - 1].second + 1);
			ans = max(ans, dp[i][j].first * dp[i][j].second);

		}
	}
	cout << ans;
	// ÄËß 2,6 ÍÅÏÐÀÂÈËÜÍÎ Ñ×ÈÒÀÅÒ

}