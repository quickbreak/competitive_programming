#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n, a, b; cin >> n >> a >> b;
	vector<vector<vector<int>>> dp(a + 1, vector<vector<int>>(b + 1, vector<int>(n + 1)));
	// dp[i][j][k] == количество способо вразместить по k коробкам i красных шаров, j синих шаров
	//base:
	for (int i = 0; i <= a; ++i) {
		for (int j = 0; j <= b; ++j) {
			for (int k = 0; k <= n; ++k) {
				dp[i][j][k] = ;
			}
		}
	}
}