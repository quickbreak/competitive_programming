#include <iostream>
#include <vector>
#include <set>


using namespace std;


void CollectSet(int u, int color, const vector<vector<int>>& adj, vector<multiset<int>>& sets_s, vector<multiset<int>>& sets_t, const string& s, const string& t, vector<int>& used) {
	used[u] = 1;
	sets_s[color].insert(s[u]);
	sets_t[color].insert(t[u]);
	for (const int& v : adj[u]) {
		if (used[v] == -1)
			CollectSet(v, color, adj, sets_s, sets_t, s, t, used);
	}
}


int main() {
	int T; cin >> T;
	while (T-- > 0) {
		int n, k; cin >> n >> k;
		string s, t; cin >> s >> t;
		vector<vector<int>>adj(n);
		for (int i = 0; i < n - k; ++i) {
			adj[i].push_back(i + k);
			adj[i + k].push_back(i);
			if (i + k + 1 < n) {
				adj[i].push_back(i + k + 1);
				adj[i + k + 1].push_back(i);
			}
		}
		vector<int>used(n, -1);
		vector<multiset<int>>sets_s(n), sets_t(n);
		for (int i = 0; i < n; ++i) {
			if (used[i] == -1) {
				CollectSet(i, i, adj, sets_s, sets_t, s, t, used);
			}
		}
		bool flag = false;
		for (int i = 0; i < n; ++i) {
			if (sets_s[i] != sets_t[i]) {
				cout << "NO\n";
				flag = true;
				break;
			}
		}
		if (!flag) {
			cout << "YES\n";
		}
	}
}
