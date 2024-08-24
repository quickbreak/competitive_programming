#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ReadFast ios_base::sync_with_stdio(false); cin.tie(0);

struct DSU {
public:
	vector<int>roots, sizes, change;
	DSU(int n):
		roots(n + 1),
		sizes(n + 1, 1),
		change(n + 1)
	{
		for(int i = 0; i < n; ++i){
			roots[i] = i;
		}
	}
	pair<int, int> update_branch(int u) {
		if (u == roots[u]) { // u - корень
			return {change[u], u};
		} else if (roots[u] == roots[roots[u]]) { // u - предкорень
			return {change[u] + change[roots[u]], roots[u]};
		} else {
			auto p = update_branch(roots[u]);
			change[u] += p.first;
			roots[u] = p.second;
			p.first = change[u];
			return p;
		}
	}
	int get_root(int u) {
		update_branch(u);
		return roots[u];
	}
	void changeColours(int u) {
		u = get_root(u);
		change[u] = 1; // см. МЫСЛЬ
	}
	int get_colour(int u) {
		// update_branch(u); гарантируется: перед вызовом метода ветка обновлена
		if (u != roots[u] && roots[u] == roots[roots[u]]) { // u - предкорень
			return (change[u] + change[roots[u]]) % 2;
		}
		return change[u] % 2; // colour[u] всегда 0
	}
	bool haveSameColour(int u, int v) {
		return get_colour(u) == get_colour(v);
	}
	void unite(int u, int v) {
		int root_u = get_root(u);
		int root_v = get_root(v);
		if (root_u == root_v)
			return;
		if (sizes[root_u] > sizes[root_v]) {
			std::swap(root_u, root_v);
			std::swap(u, v);
		}
		if (haveSameColour(u, v)) {
			changeColours(u); // меняем цвета всем вершинам компоненты, где лежит u
		}
		roots[root_u] = root_v;
		sizes[root_v] += sizes[root_u];
	}
	bool areConnected(int u, int v) {
		return get_root(u) == get_root(v);
	}
	bool canBeAdded(int u, int v) {
		return !areConnected(u, v) || !haveSameColour(u, v);
	}
};
// МЫСЛЬ: change[u] либо 0, либо 1
// увеличиться может один раз - при присоединении,
// то есть когда u перестаёт быть корнем
int main() {
	ReadFast;
	int n, m; cin >> n >> m;
	DSU dsu(n);
	int u, v, ans = -1;
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