/* 
делаем dsu
храним там ещё количество рёбер в компоненте

находим компоненту с наибольшим количеством вершин, корень которой является столицей
все компоненты, корень которых не является столицей (в том числе компоненты, состоящие из 1 вершины),
добавляем к наибольшей компоненте (увеличиваем её количество вершин, но не рёбер)

пробегаемся по компонентам
ans += количество вершин * (количество вершин - 1) - количество существовавших рёбер в компоненте
*/
#include <iostream>
#include <vector>


#define useless ios_base::sync_with_stdio(false); cin.tie(NULL);


using namespace std;


struct DSU {
	vector<int>root_, size_, reber_;

	DSU (int n) : 
		size_(vector<int>(n + 1, 1)),
		reber_(vector<int>(n + 1, 0))
	{
		root_.assign(n + 1, 0);
		for (int i = 1; i <= n; ++i) {
			root_[i] = i;
		}
	}

	int GetRoot(int u) {
		return u == root_[u] ? u : root_[u] = GetRoot(root_[u]);
	}

	void Unite(int u, int v, const vector<int>& is_capital) {
		u = GetRoot(u);
		v = GetRoot(v);

		if (u == v) {
			++reber_[u];
			return;
		}

		/*
		if (size_[v] > size_[u]) {
			swap(u, v);
		}
		*/
		if (is_capital[v]) // инвариант: столица - корень своей компоненты
			swap(u, v);

		size_[u] += size_[v];
		root_[v] = u;
		reber_[u] += reber_[v] + 1;
	}
};


int main() {
	useless;

	int n, m, k;
	cin >> n >> m >> k;
	vector<int>is_capital(n + 1, 0);
	for (int x, i = 0; i < k; ++i) {
		cin >> x;
		is_capital[x] = 1;
	}
	DSU dsu(n);
	int u, v;
	while (m-- > 0) {
		cin >> u >> v;
		dsu.Unite(u, v, is_capital);
	}

	int max_component = 0, max_size = 0;
	for (int i = 1; i <= n; ++i) {
		u = dsu.GetRoot(i);
		if (!is_capital[u])
			continue;
		if (dsu.size_[u] > max_size) {
			max_size = dsu.size_[u];
			max_component = u;
		}
	}
	for (int i = 1; i <= n; ++i) {
		u = dsu.GetRoot(i);
		if (!is_capital[u]) {
			dsu.size_[max_component] += dsu.size_[u];
			dsu.root_[u] = max_component;
			dsu.reber_[max_component] += dsu.reber_[u];
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		u = dsu.GetRoot(i);
		if (i == u) {
			ans += ((dsu.size_[u] * (dsu.size_[u] - 1)) >> 1) - dsu.reber_[u];
		}
	}
	cout << ans << '\n';
}
