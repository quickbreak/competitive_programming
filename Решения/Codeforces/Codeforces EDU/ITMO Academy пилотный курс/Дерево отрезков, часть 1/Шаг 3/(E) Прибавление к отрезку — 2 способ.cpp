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

	void add(int index, long long value, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx == index) {
				tree[x] += value;
			}
			return;
		}
		int mid = (rx + lx) / 2;
		if (index < mid)
			add(index, value, 2 * x + 1, lx, mid);
		else
			add(index, value, 2 * x + 2, mid, rx);

		tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
	}

	void add(int index, long long value) {
		add(index, value, 0, 0, size);
	}

	long long get(int index, int x, int lx, int rx) {
		if (lx >= 0 && rx - 1 <= index) {
			return tree[x];
		}
		if (lx > index) {
			return 0LL;
		}
		int mid = (rx + lx) / 2;
		return (get(index, 2 * x + 1, lx, mid) 
			  + get(index, 2 * x + 2, mid, rx));
	}

	long long get(int index) {
		return get(index, 0, 0, size);
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	/*
	Давайте построим дерево на прибавлениях. 
	При запросе прибавления на отрезке l..r значения v
	будем к левой границе прибавлять v, от правой отнимать v.
	Тогда, чтобы сказать значение элемента a[index], возьмём сумму на отрезке [0..index] 
	(получится сумма значений, которые когда-либо добавлялись к отрезкам, в которые входит a[index]).
	* Если бы элементы были ненулевыми, мы бы прибавляли к этой сумме ещё изначальное значение a[index].
	*/
	int n, m; cin >> n >> m;

	segtree ST;
	ST.init(n);
	
	int command;
	while (--m >= 0) {
		cin >> command;
		if (command == 1) {
			int l, r; long long value; cin >> l >> r >> value;
			ST.add(l, value); 
			ST.add(r, -value);
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

/*
5 5
1 0 3 3
2 1
1 2 4 4
2 3
2 4

--3
4
0

1 5
1 0 1 5
2 0
1 0 1 -2
2 0

--5
3
*/