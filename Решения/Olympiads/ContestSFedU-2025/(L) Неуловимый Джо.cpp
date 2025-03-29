#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k, l; cin >> n >> k >> l;
	vector<int>heights(n);
	for (int& height : heights)
		cin >> height;
	vector<int>dp(n, -100000000);
	dp[0] = k;
	if (n > 1) {
		if (abs(heights[1] - heights[0]) <= l || heights[1] <= l) {
			dp[1] = k;
		} else {
			dp[1] = dp[0] - 1; // k - 1
		}
	}

	for (int i = 2; i < n; ++i) {
		if (abs(heights[i] - heights[i - 1]) <= l) {
			dp[i] = dp[i - 1];
		} else {
			dp[i] = dp[i - 1] - 1;
		}
		dp[i] = max(dp[i], dp[i - 2] - (heights[i] > l) - (heights[i - 2] > l)); // n - 1 й дом
	}
	if (n > 1) {
		dp[n - 1] = max(dp[n - 1], dp[n - 2] - (heights[n - 2] > l));
	}

	if (dp[n - 1] < 0) {
		cout << "NO";
	} else {
		cout << "YES";
	}
}

/*
4 1 3
5 8 11 3
YES


4 0 3
5 8 11 3
NO


4 0 3
5 10 15 100
NO


4 0 3
5 8 11 14
YES
--------


4 0 3
10 3 6 9
YES


4 0 3
5 8 3 6
YES


4 0 3
5 8 11 52
YES


4 0 3
14 11 8 5
YES


4 0 3
14 0 3 6
YES


4 0 3
14 10 3 6
YES


4 0 3
14 10 10 10
NO


7 1 3
5 8 11 52 16 20 20
NO


5 2 3
5 20 20 4 8
YES
*/