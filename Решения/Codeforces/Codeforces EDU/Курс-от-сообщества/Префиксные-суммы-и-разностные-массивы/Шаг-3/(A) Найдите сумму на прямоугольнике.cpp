#include<iostream>
#include<vector>

using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m; cin >> n >> m;
	vector<vector<ll>>a(n + 2, vector<ll>(m + 2));
	vector<vector<ll>>prefsum(n + 2, vector<ll>(m + 2)); // prefusm[i][j] = сумма на прямоугольнике (0; 0) -> (i; j)
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			prefsum[i][j] = a[i][j];
			prefsum[i][j] += prefsum[i - 1][j] - prefsum[i - 1][j - 1];
			prefsum[i][j] += prefsum[i][j - 1];
		}
	}
	int q; cin >> q;
	int lx, ly, rx, ry;
	while (q-- > 0) {
		cin >> ly >> lx >> ry >> rx;
		cout << prefsum[ry][rx] - prefsum[ly - 1][rx] - prefsum[ry][lx - 1] + prefsum[ly - 1][lx - 1] << '\n';
	}

}