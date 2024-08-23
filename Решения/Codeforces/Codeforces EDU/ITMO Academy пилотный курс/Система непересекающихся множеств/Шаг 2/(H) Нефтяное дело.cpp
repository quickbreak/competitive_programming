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
	long long s; cin >> s;
	int u, v, w, index;
	vector<pair<pair<int, int>, pair<int, int>>>edges(m);
	for(int i = 0; i < m; ++i) {
		cin >> u >> v >> w;
		edges[i] = {{w, i + 1}, {u, v}};
	}
	std::sort(edges.begin(), edges.end());
	std::reverse(edges.begin(), edges.end());
	/* for(auto& p : edges) {
		cerr << p.first.first << ' ';
	}
	cerr << '\n'; */
	DSU graph(n);
	// соберём самый дорогой остов
	vector<pair<int, int>>useless_edges; // рёбра, после удаления которых граф останется связным
	// спойлер: рёбра минимальной стоимости
	for(int i = 0; i < m; ++i) {
		w = edges[i].first.first;
		index = edges[i].first.second;
		u = edges[i].second.first;
		v = edges[i].second.second;
		if (graph.areConnected(u, v)) { // если вершины уже связны
			useless_edges.push_back({w, index});
			continue;
		} // else:
		graph.unite(u, v);
	}
	sort(useless_edges.begin(), useless_edges.end());
	/* for(auto& p : useless_edges) {
		cerr << p.first << ' ';
	}
	cerr << '\n'; */
	long long summa = 0LL;
	int cnt = 0;
	for(auto& p : useless_edges) {
		if (summa + p.first <= s) {
			summa += p.first;
			++cnt;
		} else {
			break;
		}
	}
	cerr << "Miha, look at the answer:\n";
	cout << cnt << '\n';
	for(int i = 0; i < cnt; ++i) {
		cout << useless_edges[i].second << ' ';
	}
}