#include <vector>
#include <iostream>


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
	// Все вершины покрашены. Вершины одной компоненты связности покрашены в один цвет
	// 
	// Я утверждаю: если каждой вершине компоненты инцидентно ровно 2 ребра, эта компонента - цикл.
	vector<int>banned_colors(n + 1, 0), cnt(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		if (adj[i].size() != 2) {
			banned_colors[color[i]] = 1;
			continue;
		}
		if (!banned_colors[color[i]]) {
			cnt[color[i]]++;
		}
	}
	int ans = 0; // количество компонент-циклов
	for (int i = 1; i <= n; ++i) {
		if (!banned_colors[i] && cnt[i] > 0) {
			++ans;
		}
	}
	cout << ans << '\n';
}