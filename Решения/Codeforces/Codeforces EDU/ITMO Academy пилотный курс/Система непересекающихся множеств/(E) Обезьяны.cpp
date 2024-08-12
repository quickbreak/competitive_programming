#include <iostream>
#include <vector>
#include <set>
#include <functional>

using namespace std;

#define ReadFaster ios_base::sync_with_stdio(false);cin.tie(0);

const int inf = (int)1e9 + 7;


struct DSU {
public:
	vector<int>roots, sizes;
	DSU(int n) :
		roots(n + 1),
		sizes(n + 1, 1)
	{
		for (int i = 1; i <= n; ++i) {
			roots[i] = i;
		}
	}
	int get_root(int x) {

		if (x == roots[x])
			return x;
		else
			return get_root(roots[x]);
		

		// return (x == roots[x] ? x : roots[x] = get_root(roots[x]));
	}
	bool AreSiblings(int u, int v) {
		return get_root(u) == get_root(v);
	}
	void unite(int u, int v) {
		u = get_root(u);
		v = get_root(v);
		if (u == v)
			return;
		if (sizes[u] > sizes[v])
			swap(u, v);
		
		if (u == 1)
			swap(u, v);
		// add u to v
		roots[u] = v;
		sizes[v] += sizes[u];
	}
	void join(int u, int v) {
		if (v == -1)
			return;
		else
			unite(u, v);
	}
	bool IsConnected(int u) {
		return get_root(u) == get_root(1);
	}
};


struct hands {
public:
	int left = -1, right = -1;
};


struct query {
	int monkey, hand;
};


int main() {
	ReadFaster;
	int n, m; cin >> n >> m;
	DSU dsu(n);
	int l, r;
	set<pair<int, int>>hard_connections;
	vector<::hands>hands(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> l >> r;
		hands[i].left = l;
		hands[i].right = r;
		if (l != -1)
			hard_connections.insert({ i, 1 });
		if (r != -1)
			hard_connections.insert({ i, 2 });
	}
	vector<query>queries(m);
	int mon, han;
	for (int i = 0; i < m; ++i) {
		cin >> mon >> han;
		queries[i] = { mon, han };
		hard_connections.erase({ mon, han });
	}
	int v;
	for (auto& [u, hand] : hard_connections) {
		v = (hand == 1) ? hands[u].left : hands[u].right;
		dsu.join(u, v);
	}

	vector<int>timings(n + 1, inf);
	bool mbc, vbc; // были ли вершины mon и v соединены с 1 до этой операции? (до этого объединения)
	for (int i = m - 1; i >= 0; --i) {
		mon = queries[i].monkey;
		han = queries[i].hand;
		v = (han == 1) ? hands[mon].left : hands[mon].right;
		mon = dsu.get_root(mon); // ключевой момент: поскольку соединяются в dsu::unite корни вершин, 
		v = dsu.get_root(v); // надо и timings записывать для корней
		mbc = dsu.IsConnected(mon);
		vbc = dsu.IsConnected(v);
		dsu.join(mon, v);
		if (!mbc && dsu.IsConnected(mon)) { // не была соединена с 1, но соединилась
			timings[mon] = i;
		}
		if (!vbc && dsu.IsConnected(v)) { // не была соединена с 1, но соединилась
			timings[v] = i;
		}
	}

	function<int(int)> fill = [&timings, &dsu, &fill](int u)->int {
		if(u == 1)
			return -1;

		if (timings[u] == inf) {
			return fill(dsu.roots[u]);
		} else {
			return timings[u];
		}
	};

	for (int i = 2; i <= n; ++i) {
		if (timings[i] == inf)
			timings[i] = fill(i);
	}

	timings[1] = -1;
	for (int i = 1; i <= n; ++i) {
		cout << timings[i] << '\n';
	}
}

/*
2 0
2 -1
2 2

-1
-1
*/

/*
3 2
2 -1
-1 3
-1 -1
2 2
1 1

-1
1
0
*/

/*
3 2
2 -1
-1 3
-1 -1
1 1
2 2

-1
0
0
*/