#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n; cin >> t;
	while (--t >= 0) {
		cin >> n;
		vector<int>a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		int ans = 0;
		for (int i = 0; i < n / 2; ++i) {
			ans += a[n - i - 1] - a[i];
		}
		cout << ans << '\n';
	}
}
