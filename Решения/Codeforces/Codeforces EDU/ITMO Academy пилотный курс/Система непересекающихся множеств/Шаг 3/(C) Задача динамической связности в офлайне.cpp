#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <cassert>

using namespace std;

#define ReadFast ios_base::sync_with_stdio(false); cin.tie(0);

const pair<int*, int> k_pnul = { NULL, 0 };

struct PersDSU {
private:
	vector<int>roots, sizes;
	int components_cnt;
	pair<int*, int>p;

	int get_root(int u) {
		return (u == roots[u] ? u : get_root(roots[u]));
	}
public:
	stack<pair<int*, int>>history;
	PersDSU(int n) :
		roots(n + 1),
		sizes(n + 1, 1),
		components_cnt(n)
	{
		for (int i = 1; i <= n; ++i) {
			roots[i] = i;
		}
		history.push(k_pnul);
	}
	void unite(int u, int v) {
		u = get_root(u);
		v = get_root(v);
		if (u == v)
			return;
		if (sizes[u] > sizes[v]) {
			std::swap(u, v);
		}
		history.push({ &roots[u], roots[u] });
		history.push({ &sizes[v], sizes[v] });
		history.push({ &components_cnt, components_cnt });
		roots[u] = v;
		sizes[v] += sizes[u];
		--components_cnt;
	}
	void persist() {
		history.push({ NULL, 0 });
	}
	void rollback() {
		while (true) {
			p = history.top();
			history.pop();
			if (p == k_pnul) {
				break;
			}
			else {
				*p.first = p.second;
			}
		}
	}
	int get_components_cnt() {
		return components_cnt;
	}
};

struct Query {
	int right, left, u, v;
};

vector<int>ans;

void solve(int l, int r, const vector<Query>& edge_queries, PersDSU& dsu) {
	if (l == r - 1) {
		dsu.persist();
		for (const Query& q : edge_queries) {
			// если ребро есть в этот момент l (но его не было до него / его не будет после, 
			// поэтому оно добавляется на таком низком уровень)
			if (q.left <= l && q.right >= r) {
				dsu.unite(q.u, q.v);
			}
		}
		// самый низкий уровень, отвечаем здесь на запрос количества компонент в момент l
		ans[l] = dsu.get_components_cnt();
		dsu.rollback();
		return;
	}
	dsu.persist();
	vector<Query>edge_queries2;
	for (const Query& q : edge_queries) {
		// если ребро есть на всём [l, r] отрезке
		if (q.left <= l && q.right >= r) {
			dsu.unite(q.u, q.v);
		}
		// если ребро пересекает [l, r], то есть будет пересекать полностью часть [l, r]
		else if (q.left >= l && q.left < r || q.right > l && q.right <= r) {
			edge_queries2.push_back(q);
		}
	}
	int m = (r + l) / 2;
	solve(l, m, edge_queries2, dsu);
	solve(m, r, edge_queries2, dsu);
	dsu.rollback();
}

int main() {
	ReadFast;
	int n, q; cin >> n >> q;
	vector<Query>edge_queries; // заросы добавления - удаления ребра
	char typ;
	int u, v;
	Query qu;
	map<pair<int, int>, int>edge; // запросы добавления ребра
	vector<int>get_queries; // запросы количества компонент связности
	auto point = edge.end();
	for (int i = 0; i < q; ++i) {
		cin >> typ;
		if (typ == '+') {
			cin >> u >> v;
			if (u > v)
				swap(u, v);
			edge[{u, v}] = i;
		}
		else if (typ == '-') {
			cin >> u >> v;
			if (u > v)
				swap(u, v);
			qu.left = edge[{u, v}];
			edge.erase({ u, v });
			qu.right = i;
			qu.u = u;
			qu.v = v;
			edge_queries.push_back(qu);
		}
		else {
			get_queries.push_back(i);
		}
	}
	for (auto& p : edge) {
		qu.left = p.second;
		qu.right = q;
		qu.u = p.first.first;
		qu.v = p.first.second;
		edge_queries.push_back(qu);
	}
	PersDSU dsu(n);
	ans.assign(q, -1);
	if (q > 0) // гений на авторе добавил тест с 0 запросов
		solve(0, q, edge_queries, dsu);
	for (auto& time : get_queries) // выводим ответы на запросы количества к.с.
		cout << ans[time] << '\n';
}

/*
assert показал:
может быть запрос на добавление ребра u v
а потом на удаление v u
*/