#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ReadFast ios_base::sync_with_stdio(false); cin.tie(0);

struct DSU {
public:
	vector<int>roots, sizes;
	DSU(int n):
		roots(n + 1),
		sizes(n + 1, 1)
	{
		for(int i = 1; i <= n; ++i){
			roots[i] = i;
		}
	}
	int get_root(int u) {
		return (u == roots[u] ? u : roots[u] = get_root(roots[u]));
	}
	void unite(int u, int v) {
		u = get_root(u);
		v = get_root(v);
		if (u == v)
			return;
		if (sizes[u] > sizes[v]) {
			std::swap(u, v);
		}
		roots[u] = v;
		sizes[v] += sizes[u];
	}
	bool areConnected(int u, int v) {
		return get_root(u) == get_root(v);
	}
};

int main() {
	ReadFast;
	int n, m; cin >> n >> m;
	int u, v, w;
	vector<pair<int, pair<int, int>>>edges(m);
	for(int i = 0; i < m; ++i) {
		cin >> u >> v >> w;
		edges[i] = {w, {u, v}};
	}
	std::sort(edges.begin(), edges.end());
	DSU graph(n);
	// обрабатываем рёбра по возрастанию веса
	int max_w = -1;
	for(int i = 0; i < m; ++i) {
		w = edges[i].first;
		u = edges[i].second.first;
		v = edges[i].second.second;
		if (graph.areConnected(u, v)) { // если вершины уже связны
			continue;
		} // else:
		graph.unite(u, v);
		max_w = w;
	}
	cerr << "Miha, look at the answer:\n";
	cout << max_w;
}