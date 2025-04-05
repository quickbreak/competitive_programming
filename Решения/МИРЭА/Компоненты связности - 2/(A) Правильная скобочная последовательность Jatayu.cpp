#include <iostream>
#include <vector>
#include <map>


using namespace std;


void ColorComponent(int u, vector<int>& used, const vector<vector<int>>& adj) {
	used[u] = 1;
	for (const int& v : adj[u]) {
		if (!used[v]) {
			ColorComponent(v, used, adj);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t-- > 0) {
		int n; cin >> n;
		n <<= 1;
		string s; cin >> s;
		map<int, int>OpenedPos;
		int balance = 0, v;
		vector<vector<int>>adj(n);
		for (int i = 0; i < n; ++i) {
			if (s[i] == '(') {
				OpenedPos[balance] = i;
				++balance;
			} else {
				--balance;
				v = OpenedPos[balance];
				adj[i].push_back(v);
				adj[v].push_back(i);
			}
		}
		for (int i = 1; i < n; ++i) {
			if (s[i] == '(' && s[i - 1] == ')') {
				adj[i].push_back(i - 1);
				adj[i - 1].push_back(i);
			}
		}
		vector<int>used(n);
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (!used[i]) {
				ColorComponent(i, used, adj);
				++ans;
			}
		}
		cout << ans << '\n';
	}
}
