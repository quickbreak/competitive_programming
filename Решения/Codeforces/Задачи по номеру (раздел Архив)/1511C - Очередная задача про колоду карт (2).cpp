#include <iostream>
#include <vector>


using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q; cin >> n >> q;
	int x;
	vector<int>minpos(51, 1000000);
	for (int i = 1; i <= n; ++i) {
		cin >> x;
		minpos[x] = min(minpos[x], i);
	}
	while (--q >= 0) {
		cin >> x;
		cout << minpos[x] << ' ';
		for (int& j : minpos) {
			if (j < minpos[x])
				++j;
		}
		minpos[x] = 1;
	}
}