#include<iostream>
#include<vector>

using namespace std;

int main() {
	int t; cin >> t;
	int n;
	while (t-- > 0) {
		cin >> n;
		vector<int>a(n);
		for (auto& x : a)
			cin >> x;

		int i = 0;
		long long up = 1LL, down = 0LL;
		long long ans = 0;
		while (true) {
			while (i + 1 < n && a[i] < a[i + 1]) {
				++up;
				++i;
			}
			if (i == n - 1)
				break;
			// else
			if (up >= 2) {
				while (i + 1 < n && a[i] > a[i + 1]) {
					++down;
					++i;
				}
				ans += (up - 1) * down;
				up = 1LL;
				down = 0LL;
				if (i == n - 1)
					break;
			}
			else {
				up = 1LL;
				down = 0LL;
			}
			if (a[i] >= a[i + 1])
				++i;
		}
		cout << ans << '\n';
	}
}