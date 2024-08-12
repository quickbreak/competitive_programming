#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

#define ReadFaster ios_base::sync_with_stdio(false);cin.tie(0);

struct DSU {
public:
	vector<int>roots, sizes, min, max;
	DSU(int n) :
		roots(n + 1, 0),
		sizes(n + 1, 1),
		min(n+1),
		max(n+1)
	{
		for (int i = 1; i <= n; ++i) {
			min[i] = max[i] = roots[i] = i;
		}
	}
	int get_root(int x) {
		/*
		if (x == roots[x])
			return roots[x];
		else
			return roots[x] = get_root(roots[x]);
		*/
		return (x == roots[x] ? x : roots[x] = get_root(roots[x]));
	}
	void unite(int a, int b) {
		a = get_root(a);
		b = get_root(b);
		if (a == b)
			return;
		if (sizes[a] > sizes[b])
			swap(a, b);
		// add a to b
		roots[a] = b;
		sizes[b] += sizes[a];
		min[b] = std::min(min[a], min[b]);
		max[b] = std::max(max[a], max[b]);
	}
};


int main() {
	ReadFaster;
	int n, m; cin >> n >> m;
	string s; int u, v;
	DSU dsu(n);
	while (m-- > 0) {
		cin >> s;
		if (s[0] == 'u') {
			cin >> u >> v;
			dsu.unite(u, v);
		}
		else {
			cin >> u;
			u = dsu.get_root(u);
			cout << dsu.min[u] << ' ' << dsu.max[u] << ' ' << dsu.sizes[u] << '\n';
		}
	}
}