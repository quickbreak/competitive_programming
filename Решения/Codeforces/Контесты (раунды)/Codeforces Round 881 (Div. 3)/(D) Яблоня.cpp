#include <iostream>
#include <vector>

using namespace std;

vector<long long>childrencnt;

int dfs(vector<vector<int>>& adj, int u, int prev) {
	int cnt = 0;
	for (int v : adj[u]) {
		if (v != prev)
			cnt += dfs(adj, v, u);
	}
	if (cnt == 0) { // leaf
		return childrencnt[u] = 1;
	}
	return childrencnt[u] = cnt;	
}

int main() {
	int t, n, q; cin >> t;
	while (--t >= 0) {
		cin >> n;
		vector<vector<int>>adj(n);
		int u, v;
		childrencnt.assign(n, 0);
		for (int i = 0; i < n - 1; ++i) {
			cin >> u >> v;
			--u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		dfs(adj, 0, -1); // root`s number is 1

		cin >> q;
		while (--q >= 0) {
			cin >> u >> v;
			--u, --v;
			cout << childrencnt[u] * childrencnt[v] << '\n';
		}
	}
}

/*
--input:
2
5
1 2
3 4
5 3
3 2
4
3 4
5 1
4 4
1 3
3
1 2
1 3
3
1 1
2 3
3 1
--output:
2
2
1
4
4
1
2

--input:
2
5
5 1
1 2
2 3
4 3
2
5 5
5 1
5
3 2
5 3
2 1
4 2
3
4 3
2 1
4 2
--output:
1
2
1
4
2

*/