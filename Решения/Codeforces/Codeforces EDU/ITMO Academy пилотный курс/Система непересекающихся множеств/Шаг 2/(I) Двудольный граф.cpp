#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ReadFast ios_base::sync_with_stdio(false); cin.tie(0);

struct DSU {
private:
	vector<int>root, size, change;
	bool change_needed = false;
	
	int compressRoot(int u) {
		return (u == root[u] ? u : root[u] = compressRoot(root[u]));
	}
	int compressColour(int u) {
		return (u == root[u] ? 0 : change[u] = (compressColour(root[u]) + change[u]) % 2);
	}
	void compress(int u) {
		compressColour(u);
		compressRoot(u);
	}
	void changeColours(int u) {
		// compress(u);
		// u = root[u];
		change[u] = 1; // см. МЫСЛЬ
	}
public:
	DSU(int n):
		root(n),
		size(n, 1),
		change(n)
	{
		for(int i = 0; i < n; ++i){
			root[i] = i;
		}
	}
	bool haveSameColour(int u, int v) {
		compress(u);
		compress(v);
		return change[u] % 2 == change[v] % 2;
	}
	void unite(int u, int v) {
		change_needed = haveSameColour(u, v); // compress done, повторно нигде сжимать не надо
		u = root[u];
		v = root[v];
		if (u == v)
			return;
		if (size[u] > size[v]) {
			std::swap(u, v);
		}
		if (change_needed) {
			changeColours(u); // меняем цвета всем вершинам компоненты, где лежит u
		}
		root[u] = v;
		size[v] += size[u];
	}
};
/*
МЫСЛЬ:
когда мы присоединяем root_u к root_v, change[root_v] == 0
(и до присоединения change[root_u] тоже == 0, после, если надо, мы меняем)
*/
int main() {
	ReadFast;
	int n, q; cin >> n >> q;
	int typ, u, v, shift = 0;
	DSU dsu(n);
	while (q --> 0) {
		cin >> typ >> u >> v;
		u = (u+shift)%n;
		v = (v+shift)%n;
		if (typ == 0) {
			dsu.unite(u, v);
		} else {
			if (dsu.haveSameColour(u, v)) {
				cout << "YES\n";
				++shift;
				shift %= n;
			} else {
				cout << "NO\n";
			}
		}
	}
}