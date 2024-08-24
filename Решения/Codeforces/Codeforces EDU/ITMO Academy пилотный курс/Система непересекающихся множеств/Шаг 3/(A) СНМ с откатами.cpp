#include <iostream>
#include <vector>
#include<stack>

using namespace std;

#define ReadFast ios_base::sync_with_stdio(false); cin.tie(0);

const pair<int*, int> k_pnul = {NULL, 0};

struct PersDSU {
public:
	vector<int>roots, sizes;
	int components_cnt;
	stack<pair<int*, int>>history;
	pair<int*, int>p;
	PersDSU(int n) :
		roots(n + 1),
		sizes(n + 1, 1),
		components_cnt(n)
	{
		for(int i = 0; i < n; ++i){
			roots[i] = i;
		}
		history.push(k_pnul);
	}
	int get_root(int u) {
		return (u == roots[u] ? u : get_root(roots[u]));
	}
	int unite(int u, int v) {
		u = get_root(u);
		v = get_root(v);
		if (u == v)
			return components_cnt;
		if (sizes[u] > sizes[v]) {
			std::swap(u, v);
		}
		history.push({ &roots[u], roots[u] });
		history.push({&sizes[v], sizes[v]});
		history.push({&components_cnt, components_cnt});
		roots[u] = v;
		sizes[v] += sizes[u];
		--components_cnt;
		return components_cnt;
	}
	void persist(){
		history.push({NULL, 0});
	}
	int rollback() {
		while(true) {
			p = history.top();
			history.pop();
			if (p == k_pnul) {
				break;
			} else {
				*p.first = p.second;
			}
		}
		return components_cnt;
	}
};

int main() {
	ReadFast;
	int n, q; cin >> n >> q;
	PersDSU dsu(n);
	int u, v;
	std::string typ;
	while (q --> 0) {
		cin >> typ;
		if (typ[0] == 'u') {
			cin >> u >> v;
			cout << dsu.unite(u, v) << '\n';
		} else if (typ[0] == 'p') {
			dsu.persist();
		} else {
			cout << dsu.rollback() << '\n';
		}
	}
}