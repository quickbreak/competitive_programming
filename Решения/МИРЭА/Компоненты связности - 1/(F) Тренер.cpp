#include <iostream>
#include <vector>
#include <set>


#define useless ios_base::sync_with_stdio(false); cin.tie(NULL);


using namespace std;


struct DSU {
	vector<int>root_, size_;

	DSU(int n) :
		size_(vector<int>(n + 1, 1))
	{
		root_.assign(n + 1, 0);
		for (int i = 1; i <= n; ++i) {
			root_[i] = i;
		}
	}

	int GetRoot(int u) {
		return u == root_[u] ? u : root_[u] = GetRoot(root_[u]);
	}

	void Unite(int u, int v) {
		u = GetRoot(u);
		v = GetRoot(v);

		if (u == v) {
			return;
		}


		if (size_[v] > size_[u]) {
			swap(u, v);
		}

		size_[u] += size_[v];
		root_[v] = u;
	}

	int GetSize(int u) {
		return size_[GetRoot(u)];
	}
};


int main() {
	useless;

	int n, m; cin >> n >> m;
	int u, v;
	DSU dsu(n);
	while (m-- > 0) {
		cin >> u >> v;
		dsu.Unite(u, v);
	}

	for (int u = 1; u <= n; ++u) {
		if (dsu.GetSize(u) > 3) {
			cout << -1;
			return 0;
		}
	}

	for (int u = 1; u <= n; ++u) {
		if (dsu.GetSize(u) < 3) {
			for (int v = 1; v <= n; ++v) {
				if (dsu.GetSize(v) == 3 - dsu.GetSize(u)) { // это исключает u == v
					dsu.Unite(u, v);
				}
			}
		}
	}

	set<int>sigmy;
	for (int u = 1; u <= n; ++u) {
		if (dsu.GetSize(u) == 2) {
			cout << -1;
			return 0;
		}
		else if (dsu.GetSize(u) == 1) {
			sigmy.insert(u);
		}
	}

	set<int>printed;
	for (int u = 1; u <= n; ++u) {
		if (dsu.GetSize(u) == 3 && !printed.contains(dsu.GetRoot(u))) {
			cout << u << ' ';
			for (int v = 1; v <= n; ++v) {
				if (u != v && dsu.GetRoot(v) == dsu.GetRoot(u)) {
					cout << v << ' ';
				}
			}
			cout << '\n';
			printed.insert(dsu.GetRoot(u));
		}
	}
	while (!sigmy.empty()) {
		for (int i = 0; i < 3; ++i) {
			cout << *sigmy.begin() << ' ';
			sigmy.erase(sigmy.begin());
		}
		cout << '\n';
	}
}