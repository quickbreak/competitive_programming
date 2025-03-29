#include <vector>
#include <iostream>
#include <set>


#define useless ios_base::sync_with_stdio(false); cin.tie(NULL);


using namespace std;


void dfs(int u, vector<int>& color, const vector<vector<int>>& adj, int prev_col) {
	color[u] = prev_col;
	for (const int& v : adj[u]) {
		if (color[v] == 0) // если мы ещё не покрасили её (этим цветом, мы не могли покрасить её другим)
			dfs(v, color, adj, prev_col);
	}
	return;
}


const int kInf = (int)1e9 + 7;


int main() {

	useless;

	int n, m; cin >> n >> m;
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
	vector<int>color(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		if (color[i] == 0)
			dfs(i, color, adj, i);
	}
	vector<int>res(n + 1, kInf);
	for (int i = 1; i <= n; ++i) {
		res[color[i]] = min(res[color[i]], c[i]);
	}
	long long ans = 0;
	for (const int& cost : res) {
		if (cost != kInf) {
			ans += cost;
		}
	}
	cout << ans;
}