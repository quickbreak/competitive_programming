#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ReadFast ios_base::sync_with_stdio(false); cin.tie(0);

struct DSU {
private:
	vector<int>root, size, change;
	bool change_needed = false;
	
	pair<int, int> compress(int u) {
		if (u == root[u]) {
			return {0, u};
		} else {
			auto p = compress(root[u]);
			change[u] += p.first;
			change[u] %= 2;
			root[u] = p.second;
			return {change[u], root[u]};
		}
	}
	void changeColours(int u) {
		change[u] = 1; // см. МЫСЛЬ
	}
	bool areConnected(int u, int v) {
		return root[u] == root[v];
	}
	bool haveSameColour(int u, int v) {
		compress(u);
		compress(v);
		return change[u] == change[v];
	}
public:
	DSU(int n):
		root(n + 1),
		size(n + 1, 1),
		change(n + 1)
	{
		for(int i = 1; i <= n; ++i){
			root[i] = i;
		}
	}
	void unite(int u, int v) {
		change_needed = haveSameColour(u, v); // compress done, повторно нигде сжимать не надо
		u = root[u];
		v = root[v];
		if (u == v)
			return;
		if (size[u] > size[v]) {
			std::swap(u, v);
		}
		if (change_needed) {
			changeColours(u); // меняем цвета всем вершинам компоненты, где лежит u
		}
		root[u] = v;
		size[v] += size[u];
	}
	bool canBeAdded (int u, int v) {
		return !haveSameColour(u, v) || !areConnected(u, v);
	}
};
/*
МЫСЛЬ:
когда мы присоединяем root_u к root_v, change[root_v] == 0
(и до присоединения change[root_u] тоже == 0, после, если надо, мы меняем)
*/
int main() {
	ReadFast;
	int n, m; cin >> n >> m;
	int u, v, ans = -1;
	DSU dsu(n);
	for (int i = 1; i <= m; ++i) {
		cin >> u >> v;
		if (dsu.canBeAdded(u, v)) {
			dsu.unite(u, v);
		} else if (ans == -1) {
			ans = i;
		}
	}
	cout << ans;
}