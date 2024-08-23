#include <iostream>
#include <vector>

using namespace std;

#define ReadFast ios_base::sync_with_stdio(false); cin.tie(0);

struct DSU {
public:
	vector<int>roots;
	int N;
	bool nth_deleted;
	DSU(int n):
		roots(n + 1),
		N(n),
		nth_deleted(false)
	{
		for(int i = 1; i <= n; ++i){
			roots[i] = i;
		}
	}
	int get_root(int u){
		return (u == roots[u] ? u : (roots[u] = get_root(roots[u])));
	}
	void del(int u) {
		if (u == N){
			nth_deleted = true;
			return;
		}
		int v = u + 1;
		v = get_root(v);
		roots[u] = v;
	}
	int get_neighbour(int u) {
		int pal = get_root(u);
		return ((pal == N && nth_deleted) ? -1 : pal);
	}
};

int main() {
	ReadFast;
	int n, m; cin >> n >> m;
	int x;
	char typ;
	DSU dsu(n);
	while (m --> 0) {
		cin >> typ >> x;
		if (typ == '-') {
			dsu.del(x);
		} else {
			cout << dsu.get_neighbour(x) << '\n';
		}
	}
}