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
	int unite(int u, int v) {
		u = get_root(u);
		v = get_root(v);
		if (u == v)
			return sizes[u];
		if (sizes[u] > sizes[v]) {
			std::swap(u, v);
		}
		roots[u] = v;
		sizes[v] += sizes[u];
		return sizes[v];
	}
	bool areConnected(int u, int v) {
		return get_root(u) == get_root(v);
	}
};

const long long inf = (long long)1e9+2;
const long long inf2 = 2LL*inf+2;

int main() {
	ReadFast;
	int n, m; cin >> n >> m;
	int u, v;
	long long w;
	vector<pair<long long, pair<int, int>>>edges(m);
	for(int i = 0; i < m; ++i) {
		cin >> u >> v >> w;
		edges[i] = {w, {u, v}};
	}
	std::sort(edges.begin(), edges.end());
	bool ok; // получился связный граф? (остов)
	long long max_w, min_w, diff;
	diff = inf2;
	for(int j = 0; j < m; ++j) {
		DSU graph(n);
		ok = false;
		max_w = -inf;
		min_w = inf;
		for (int i = j; i < m; ++i) {
			w = edges[i].first;
			u = edges[i].second.first;
			v = edges[i].second.second;
			if (graph.areConnected(u, v)) { // если вершины уже связны
				continue;
			} // else:
			max_w = std::max(max_w, w);
			min_w = std::min(min_w, w);
			if (graph.unite(u, v) == n) { // оптимальный для данного j остов собран
				ok = true;
				break;
			}
		}
		if (ok) {
			diff = min(diff, max_w - min_w);
		}
	}
	if (diff < inf2) {
		cout << "YES\n" << diff;
	} else {
		cout << "NO\n";
	}
}