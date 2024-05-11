#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct segtree {
	vector<long long>tree;
	int size = 1;

	void init(int n) {
		while (size < n)
			size *= 2;
		tree.assign(2 * size - 1, 0LL);
	}

	void add(int l, int r, long long value, int x, int lx, int rx) {
		if (lx >= l && rx <= r) {
			tree[x] += value;
			return;
		}
		if (lx >= r || rx <= l)
			return;
		int mid = (rx + lx) / 2;
		add(l, r, value, 2 * x + 1, lx, mid);
		add(l, r, value, 2 * x + 2, mid, rx);
	}

	void add(int l, int r, long long value) {
		add(l, r, value, 0, 0, size);
	}

	long long get(int index, long long balance, int x, int lx, int rx) {
		if (rx - lx == 1) {
			return tree[x] + balance;
		}
		int mid = (rx + lx) / 2;
		if (index < mid)
			return get(index, balance + tree[x], 2 * x + 1, lx, mid);
		else
			return get(index, balance + tree[x], 2 * x + 2, mid, rx);
	}

	long long get(int index) {
		return get(index, 0LL, 0, 0, size);
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	/*
	Давайте будем сохранять прибавления на отрезке в вершинах дерева, 
	которые отвечают за весь этот отрезок или его часть.
	Тогда, чтобы сказать значение элемента a[index], спустимся по дереву от корня до этого элемента, 
	складывая все прибавления на пути (это сумма значений, которые когда-либо добавлялись к отрезкам, 
	в которые входит a[index])
	*/
	int n, m; cin >> n >> m;

	segtree ST;
	ST.init(n);
	
	int command;
	while (--m >= 0) {
		cin >> command;
		if (command == 1) {
			int l, r; long long value; cin >> l >> r >> value;
			ST.add(l, r, value);
		}
		else {
			int index; cin >> index;
			cout << ST.get(index) << '\n';
		}
	}
}

/*
Есть массив из n элементов, изначально заполненный НУЛЯМИ. 
Вам нужно написать структуру данных, которая обрабатывает два вида запросов:
1) прибавить к отрезку от l до r-1число v
2) узнать текущее значение в ячейке i
*/
