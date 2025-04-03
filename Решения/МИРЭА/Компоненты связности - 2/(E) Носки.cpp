#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>


using namespace std;


void Func(int u, const vector<vector<int>>& adj, vector<int>& used, map<int, int>& cnt, const vector<int>& color) {
	used[u] = 1;
	++cnt[color[u]];
	for (const int& v : adj[u]) {
		if (!used[v]) {
			Func(v, adj, used, cnt, color);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, k; cin >> n >> m >> k;
	vector<int>c(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> c[i];
	vector<vector<int>>adj(n + 1);
	int u, v;
	while (m-- > 0) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int>used(n + 1);
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (!used[i]) {
			map<int, int>cnt;
			Func(i, adj, used, cnt, c);
			int max_count = 0;
			for (auto& p : cnt) {
				ans += p.second;
				max_count = max(max_count, p.second);
			}
			ans -= max_count;
		}
	}
	cout << ans;
}
