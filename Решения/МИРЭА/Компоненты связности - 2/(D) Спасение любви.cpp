#include <iostream>
#include <vector>


using namespace std;


struct DSU {
	vector<int> roots_, size_;
	DSU() :
		roots_(26),
		size_(26, 1)
	{
		for (int i = 0; i < 26; ++i) {
			roots_[i] = i;
		}
	}

	int GetRoot(int u) {
		return (u == roots_[u] ? u : roots_[u] = GetRoot(roots_[u]));
	}

	void Unite(int u, int v) {
		u = GetRoot(u);
		v = GetRoot(v);

		if (u == v)
			return;

		if (size_[u] > size_[v]) {
			swap(u, v);
		}

		size_[v] += size_[u];
		roots_[u] = v;
 	}

	bool AreConnected(int u, int v) {
		u = GetRoot(u);
		v = GetRoot(v);
		return u == v;
	}
};


vector<pair<char, char>> Func(int n, const string& s, const string& t) {
	vector<pair<char, char>> res;
	DSU dsu;
	for (int i = 0; i < n; ++i) {
		if (!dsu.AreConnected(s[i] - 'a', t[i] - 'a')) {
			dsu.Unite(s[i] - 'a', t[i] - 'a');
			res.push_back({ s[i], t[i] });
		}
	}
	return res;
}


int main() {
	int n; cin >> n;
	string s, t; cin >> s >> t;
	vector<pair<char, char>> res = Func(n, s, t);
	cout << res.size() << '\n';
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i].first << ' ' << res[i].second << '\n';
	}
}
