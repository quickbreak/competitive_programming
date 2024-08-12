#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

#define ReadFaster ios_base::sync_with_stdio(false);cin.tie(0);

struct DSU {
public:
	vector<int>roots, sizes;
	DSU(int n) :
		roots(n + 1, 0),
		sizes(n + 1, 1)
	{
		for (int i = 1; i <= n; ++i) {
			roots[i] = i;
		}
	}
	int get_root(int x) {
		/*
		if (x == roots[x])
			return roots[x];
		else
			return roots[x] = get_root(roots[x]);
		*/
		return (x == roots[x] ? x : roots[x] = get_root(roots[x]));
	}
	void AddEdge(int u, int v) {
		u = get_root(u);
		v = get_root(v);
		if (u == v)
			return;
		if (sizes[u] > sizes[v])
			swap(u, v);
		// add u to v
		roots[u] = v;
		sizes[v] += sizes[u];
	}
	bool InOneComponent(int u, int v) {
		return get_root(u) == get_root(v);
	}
};


int main() {
	ReadFaster;
	int n, m, k; cin >> n >> m >> k;
	string s; int u, v;
	while (m-- > 0) {
		cin >> u >> v;
	}
	vector<tuple<char, int, int>>queries; // a - add, c - check
	for (int i = 0; i < k; ++i) {
		cin >> s;
		cin >> u >> v;
		queries.push_back({ (s[0] == 'c' ? 'a' : 'c'), u, v });
	}
	DSU dsu(n);
	vector<string>res(k);
	for (int i = queries.size() - 1; i >= 0; --i) {
		auto tup = queries[i];
		u = get<1>(tup);
		v = get<2>(tup);
		if (get<0>(tup) == 'a') {
			dsu.AddEdge(u, v);
		} else {
			res[i] = (dsu.InOneComponent(u, v) ? "YES\n" : "NO\n");
		}
	}
	for (string s : res)
		cout << s;
}