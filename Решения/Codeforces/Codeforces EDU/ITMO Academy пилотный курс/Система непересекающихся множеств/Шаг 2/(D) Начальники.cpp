#include <iostream>
#include <vector>

using namespace std;

#define ReadFast ios_base::sync_with_stdio(false); cin.tie(0);

struct DSU {
public:
	vector<int>roots, heights;
	DSU(int n):
		roots(n + 1),
		heights(n + 1)
	{
		for(int i = 1; i <= n; ++i){
			roots[i] = i;
		}
	}
	int updateBranch(int u) {
		if (u == roots[u] || roots[u] == roots[roots[u]]) {
			return roots[u];
		} else {
			int root = updateBranch(roots[u]);
			// сколько мне до текущего корня + сколько ему до корня
			heights[u] = heights[u] + heights[roots[u]]; 
			roots[u] = root;
			return root;
		}
	}
	void subordinate(int u, int v) {
		if (roots[u] != v) {
			roots[u] = v;
			heights[u] = 1;
		}
	}
	int getHeight(int u) {
		updateBranch(u);
		return heights[u];
	}
};

int main() {
	ReadFast;
	int n, q; cin >> n >> q;
	int u, v, typ;
	DSU dsu(n);
	while (q --> 0) {
		cin >> typ >> u;
		if (typ == 1) {
			cin >> v;
			dsu.subordinate(u, v);
		} else {
			cout << dsu.getHeight(u) << '\n';
		}
	}
}