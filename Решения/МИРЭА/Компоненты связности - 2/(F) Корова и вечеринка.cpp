#include <iostream>
#include <vector>


using namespace std;


void Func(int u, const vector<vector<pair<int, int>>>& adj, vector<int>& used_meats, int& happy_count) {
	used_meats[u] = 1;
	for (const auto& p : adj[u]) {
		if (!used_meats[p.first]) {
			++happy_count;
			Func(p.first, adj, used_meats, happy_count);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k; cin >> n >> k;
	// vector<int>fav_meats(k);
	vector<vector<pair<int, int>>> adj(n + 1);
	int u, v;
	for (int  i = 0; i < k; ++i) {
		cin >> u >> v;
		adj[u].push_back({ v, i });
		adj[v].push_back({ u, i });
	}
	vector<int>used(n + 1);
	int happy_count = 0;
	for (int u = 1; u <= n; ++u) {
		if (!used[u]) {
			Func(u, adj, used, happy_count);
		}
	}
	cout << k - happy_count;
}


/*
6 4
1 2
2 3
2 4
2 4
-- 1

6 4
1 2
2 3
4 5
5 6
-- 0

6 3
1 2
2 3
4 5
-- 0

6 4
1 2
2 3
4 5
4 5
-- 1

2 2
1 2
1 2
-- 1
*/