#include <iostream>
#include <vector>

using namespace std;

#define ReadFast ios_base::sync_with_stdio(false); cin.tie(0);

struct DSU {
public:
	vector<int>roots;
	int N;
	DSU(int n):
		roots(n + 1),
		N(n)
	{
		for(int i = 1; i <= n; ++i){
			roots[i] = i;
		}
	}
	int get_root(int u){
		return (u == roots[u] ? u : (roots[u] = get_root(roots[u])));
	}
	int park(int u) {
		u = get_root(u);
		int v = (u + 1) % N;
		if (v == 0)
			v = N;
		v = get_root(v);
		roots[u] = v;
		return u;
	}
};

int main() {
	ReadFast;
	int n; cin >> n;
	int x;
	DSU dsu(n);
	while (n --> 0) {
		cin >> x;
		cout << dsu.park(x) << ' ';
	}
}