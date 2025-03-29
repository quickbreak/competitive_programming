#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int main() {
	int n; cin >> n;
	vector<int>a(n);
	for (int& x : a)
		cin >> x;
	sort(a.begin(), a.end());
	if (n == 1) {
		cout << 0;
		return 0;
	} else if (n == 2) {
		cout << a[1] - a[0];
		return 0;
	} else if (n == 3) {
		cout << a[2] - a[0];
		return 0;
	}
	vector<int>dp(n);
	dp[0] = 0;
	dp[1] = a[1] - a[0];
	dp[2] = a[2] - a[0];
	for (int i = 3; i < n; ++i) {
		dp[i] = min(dp[i - 1] + a[i] - a[i - 1], dp[i - 2] + a[i] - a[i - 1]);
	}
	cout << dp[n - 1];
}
