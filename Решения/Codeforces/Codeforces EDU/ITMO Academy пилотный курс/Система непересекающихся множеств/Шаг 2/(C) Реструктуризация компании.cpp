#include <iostream>
#include <vector>

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
	bool areSiblings(int u, int v) {
		return get_root(u) == get_root(v);
	}
};

struct DSUSegments {
public:
	vector<int>roots, sizes, rights;
	DSUSegments(int n):
		roots(n + 1),
		sizes(n + 1, 1),
		rights(n + 1)
	{
		for(int i = 1; i <= n; ++i){
			rights[i] = roots[i] = i;
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
		rights[v] = std::max(rights[u], rights[v]);
	}
	int get_right(int u) {
		return rights[u];
	}
};

int main() {
	ReadFast;
	int n, q; cin >> n >> q;
	int x, y, typ;
	DSU dsu(n);
	DSUSegments dsuseg(n);
	while (q --> 0) {
		cin >> typ >> x >> y;
		if (typ == 1) {
			dsu.unite(x, y);
		} else if (typ == 2) {
			x = dsuseg.get_root(x);
			while (dsuseg.get_right(x) < y) {
				int v = dsuseg.get_right(x) + 1;
				dsuseg.unite(x, v);
				dsu.unite(x, v);
				x = dsuseg.get_root(x);
			}
		} else {
			cout << (dsu.areSiblings(x, y) ? "YES\n" : "NO\n");
		}
	}
}