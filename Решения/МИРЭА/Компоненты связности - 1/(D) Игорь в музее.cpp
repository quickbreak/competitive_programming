#include <iostream>
#include <vector>


#define useless ios_base::sync_with_stdio(false); cin.tie(NULL);


using namespace std;


struct DSU {
	vector<int>root_, size_, pics_;

	DSU(int n, int m, vector<int> pics) :
		size_(vector<int>((n + 2)* (m + 2), 1)),
		pics_(pics)
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
		pics_[u] += pics_[v];
	}

	int GetPicsCount(int u) {
		return pics_[GetRoot(u)];
	}
};


int main() {
	useless;

	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<char>>museum(n + 2, vector<char>(m + 2));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> museum[i][j];
		}
	}
	vector<int>pics((n + 2) * (m + 2));
	int number;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (museum[i][j] == '.') {
				number = (i - 1) * m + j;
				pics[number] = (museum[i][j - 1] == '*') + (museum[i - 1][j] == '*') + (museum[i + 1][j] == '*') + (museum[i][j + 1] == '*');
			}
		}
	}
	int bumber;
	DSU dsu(n, m, pics);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (museum[i][j] == '.') {
				number = (i - 1) * m + j;
				if (museum[i - 1][j] == '.') {
					bumber = (i - 1 - 1) * m + j;
					dsu.Unite(number, bumber);
				}
				if (museum[i + 1][j] == '.') {
					bumber = (i + 1 - 1) * m + j;
					dsu.Unite(number, bumber);
				}
				if (museum[i][j - 1] == '.') {
					bumber = (i - 1) * m + j - 1;
					dsu.Unite(number, bumber);
				}
				if (museum[i][j + 1] == '.') {
					bumber = (i - 1) * m + j + 1;
					dsu.Unite(number, bumber);
				}
			}
		}
	}
	int x, y;
	while (k-- > 0) {
		cin >> x >> y;
		cout << dsu.GetPicsCount((x - 1) * m + y) << '\n';
	}
}
