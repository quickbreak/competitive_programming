#include <iostream>
#include <vector>


using namespace std;


struct DSU {
	vector<int> roots_, size_, rooks_count_;
	DSU(int n) :
		roots_(n + 1),
		size_(n + 1, 1),
		rooks_count_(n + 1, 0)
	{
		for (int i = 1; i <= n; ++i) {
			roots_[i] = i;
		}
	}

	int GetRoot(int u) {
		return (u == roots_[u] ? u : roots_[u] = GetRoot(roots_[u]));
	}

	void Unite(int u, int v) {
		u = GetRoot(u);
		v = GetRoot(v);

		if (u == v) {
			++rooks_count_[u];
			return;
		}

		if (size_[u] > size_[v]) {
			swap(u, v);
		}

		size_[v] += size_[u];
		roots_[u] = v;
		rooks_count_[v] += rooks_count_[u];
		++rooks_count_[v];
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t-- > 0) {
		int n, m; cin >> n >> m;
		DSU dsu(n);
		int u, v;
		while (m-- > 0) {
			cin >> u >> v;
			if (u != v)
				dsu.Unite(u, v);
		}
		vector<int>used(n + 1);
		int ans = 0;
		for (int cell = 1; cell <= n; ++cell) {
			u = dsu.GetRoot(cell);
			if (!used[u]) {
				if (dsu.rooks_count_[u] == dsu.size_[u] - 1) {
					ans += dsu.rooks_count_[u];
				} else {
					ans += dsu.rooks_count_[u] + 1;
				}
				used[u] = 1;
			}
		}
		cout << ans << '\n';
	}
}
