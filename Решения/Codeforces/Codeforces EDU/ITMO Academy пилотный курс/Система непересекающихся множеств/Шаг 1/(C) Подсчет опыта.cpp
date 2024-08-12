#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

#define ReadFaster ios_base::sync_with_stdio(false);cin.tie(0);

struct DSU {
public:
	vector<int>roots, sizes, addition;
	DSU(int n) :
		roots(n + 1),
		sizes(n + 1, 1),
		addition(n + 1)
	{
		for (int i = 1; i <= n; ++i) {
			roots[i] = i;
		}
	}
	int get_root(int x) {

		if (x == roots[x])
			return x;
		else
			return get_root(roots[x]);

		// return (x == roots[x] ? x : roots[x] = get_root(roots[x]));
	}
	void unite(int u, int v) {
		u = get_root(u);
		v = get_root(v);
		if (u == v)
			return;
		if (sizes[u] > sizes[v])
			swap(u, v);
		// add u to v
		roots[u] = v;
		sizes[v] += sizes[u];

		addition[u] -= addition[v];
	}
	void add(int u, int value) {
		u = get_root(u);
		addition[u] += value;
	}
	int show(int u) {
		int balance = addition[u];
		while (u != roots[u]) {
			u = roots[u];
			balance += addition[u];
		}
		return balance;
	}
};


int main() {
	ReadFaster;
	int n, m, k; cin >> n >> m;
	string s; int u, v, value;
	DSU dsu(n);
	while (m-- > 0) {
		cin >> s;
		switch (s[0]) {
		case 'j': {
			cin >> u >> v;
			dsu.unite(u, v);
			break;
		}
		case 'a': {
			cin >> u >> value;
			dsu.add(u, value);
			break;
		}
		case 'g': {
			cin >> u;
			cout << dsu.show(u) << '\n';
			break;
		}
		default:
			break;
		}
	}
}