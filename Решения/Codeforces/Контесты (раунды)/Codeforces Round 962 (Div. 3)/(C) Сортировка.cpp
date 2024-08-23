#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t;
	int n, q;
	string a, b;
	int l, r, res;
	while (t-- > 0) {
		cin >> n >> q;
		cin >> a >> b;

		vector<vector<int>>cnta(26, vector<int>(n + 1)), cntb(26, vector<int>(n + 1));
		for (int i = 0; i < n; ++i) {
			for (int x = 0; x < 26; ++x) {
				cnta[x][i + 1] = cnta[x][i];
				cntb[x][i + 1] = cntb[x][i];
				if (x == a[i] - 'a') {
					++cnta[x][i + 1];
				}
				if (x == b[i] - 'a') {
					++cntb[x][i + 1];
				}
			}
		}
		
		while (q-- > 0) {
			cin >> l >> r;
			res = 0;
			for (int x = 0; x < 26; ++x) {
				res += max(0, (cnta[x][r] - cnta[x][l - 1]) - (cntb[x][r] - cntb[x][l - 1]));
			}
			cout << res << '\n';
		}
	}
}