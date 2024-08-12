#include <iostream>
#include <vector>

using namespace std;

#define ReadFaster ios_base::sync_with_stdio(false);cin.tie(0);

struct DSU {
private:
	vector<int>roots, sizes;
	int get_root(int x) {
		/*
		if (x == roots[x])
			return roots[x];
		else
			return roots[x] = get_root(roots[x]);
		*/
		return (x == roots[x] ? x : roots[x] = get_root(roots[x]));
	}
public:
	DSU(int n):
		roots(n+1, 0),
		sizes(n+1,1)
	{
		for (int i = 1; i <= n; ++i) {
			roots[i] = i;
		}
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
	}
	bool are_siblings(int a, int b) {
		return (get_root(a) == get_root(b));
	}
};


int main() {
	ReadFaster;
	int n, m; cin >> n >> m;
	string s; int u, v;
	DSU dsu(n);
	while (m-- > 0) {
		cin >> s >> u >> v;
		if (s[0] == 'u') {
			dsu.unite(u, v);
		} else {
			cout << (dsu.are_siblings(u, v) ? "YES\n" : "NO\n");
		}
	}
}