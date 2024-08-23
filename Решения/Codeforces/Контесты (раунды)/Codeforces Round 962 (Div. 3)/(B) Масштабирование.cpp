#include <bits/stdc++.h>

using namespace std;

int main() {
	int t; cin >> t;
	int n, k;
	char x;
	while (t-- > 0) {
		cin >> n >> k;
		vector<vector<char>>a(n, vector<char>(n));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> a[i][j];
			}
		}
		int m = n / k;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < m; ++j) {
				cout << a[i * k][j * k];
			}
			cout << '\n';
		}
	}
}