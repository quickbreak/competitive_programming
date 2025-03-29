#include <iostream>
#include <vector>


using namespace std;


void GetGroupSize(int u, vector<int>& used, vector<vector<int>>& adj, int root, vector<int>& roots, int& group_size) {
	roots[u] = root;
	used[u] = 1;
	group_size += 1;
	for (int v : adj[u]) {
		if (!used[v])
			GetGroupSize(v, used, adj, root, roots, group_size);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m; cin >> n >> m;
	int k;
	vector<vector<int>>adj(n+1);
	int prev_vertex = -1, curr_vertex;
	while (m-->0) {
		cin >> k;
		prev_vertex = -1;
		while (k-->0) {
			cin >> curr_vertex;
			if (prev_vertex != -1) {
				adj[curr_vertex].push_back(prev_vertex);
				adj[prev_vertex].push_back(curr_vertex);
			}
			prev_vertex = curr_vertex;
		}
	}
	vector<int>used(n + 1), roots(n + 1), cnt(n + 1);
	for (int i = 1; i <= n; ++i) {
		if (!used[i]) {
			GetGroupSize(i, used, adj, i, roots, cnt[i]);
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << cnt[roots[i]] << ' ';
	}
}