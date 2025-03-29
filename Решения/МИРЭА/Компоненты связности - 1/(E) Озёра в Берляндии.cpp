#include <iostream>
#include <vector>
#include <set>


#define useless ios_base::sync_with_stdio(false); cin.tie(NULL);


using namespace std;


struct DSU {
	vector<int>root_, size_;

	DSU(int n, int m) :
		size_(vector<int>((n + 2) * (m + 2), 1))
	{
		root_.assign((n + 2) * (m + 2), 0);
		for (int i = 0; i < (n + 2) * (m + 2); ++i) {
			root_[i] = i;
		}
	}

	int GetRoot(int u) {
		return u == root_[u] ? u : root_[u] = GetRoot(root_[u]);
	}

	void Unite(int u, int v) {
		u = GetRoot(u);
		v = GetRoot(v);

		if (u == v) {
			return;
		}

		
		if (size_[v] > size_[u]) {
			swap(u, v);
		}
		
		size_[u] += size_[v];
		root_[v] = u;
	}

	int GetSize(int u) {
		return size_[GetRoot(u)];
	}
};


int main() {
	useless;

	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<char>>lake(n + 2, vector<char>(m + 2));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> lake[i][j];
		}
	}
	int number;
	int bumber;
	DSU dsu(n, m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (lake[i][j] == '.') {
				number = (i - 1) * m + j;
				if (lake[i - 1][j] == '.') {
					bumber = (i - 1 - 1) * m + j;
					dsu.Unite(number, bumber);
				}
				if (lake[i + 1][j] == '.') {
					bumber = (i + 1 - 1) * m + j;
					dsu.Unite(number, bumber);
				}
				if (lake[i][j - 1] == '.') {
					bumber = (i - 1) * m + j - 1;
					dsu.Unite(number, bumber);
				}
				if (lake[i][j + 1] == '.') {
					bumber = (i - 1) * m + j + 1;
					dsu.Unite(number, bumber);
				}
			}
		}
	}
	set<int>banned;
	for (int i = 1; i <= n; ++i) {
		if (lake[i][1] == '.') {
			number = (i - 1) * m + 1;
			banned.insert(dsu.GetRoot(number));
		}
		if (lake[i][m] == '.') {
			number = (i - 1) * m + m;
			banned.insert(dsu.GetRoot(number));
		}
	}
	for (int j = 1; j <= m; ++j) {
		if (lake[1][j] == '.') {
			number = (1 - 1) * m + j;
			banned.insert(dsu.GetRoot(number));
		}
		if (lake[n][j] == '.') {
			number = (n - 1) * m + j;
			banned.insert(dsu.GetRoot(number));
		}
	}

	set<pair<int, int>>st;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (lake[i][j] == '.') {
				number = (i - 1) * m + j;
				number = dsu.GetRoot(number);
				if (!banned.contains(number)) { 
					st.insert({ dsu.GetSize(number), number });
				}
			}
		}
	}

	int ans = 0;
	set<int>removed;
	while (st.size() > k) {
		ans += (*st.begin()).first;
		removed.insert((*st.begin()).second);
		st.erase(st.begin());
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (lake[i][j] == '.') {
				number = (i - 1) * m + j;
				number = dsu.GetRoot(number);
				if (removed.contains(number)) {
					lake[i][j] = '*';
				}
			}
		}
	}

	cout << ans << '\n'; 
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cout << lake[i][j];
		}
		cout << '\n';
	}
}
