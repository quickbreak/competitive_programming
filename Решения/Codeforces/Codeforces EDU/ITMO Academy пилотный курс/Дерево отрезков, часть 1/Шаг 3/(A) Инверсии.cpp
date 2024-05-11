#include <iostream>
#include <vector>


using namespace std;


struct segtree {
	vector<int>tree;
	int size = 1;

	void init(int n) {
		while (size < n)
			size *= 2;
		tree.assign(2 * size - 1, 0);
	}

	void set(int index, int x, int lx, int rx) {
		if (rx - lx == 1) {
			tree[x] = 1;
			return;
		}
		int mid = (rx + lx) / 2;
		if (index < mid)
			set(index, 2 * x + 1, lx, mid);
		else 
			set(index, 2 * x + 2, mid, rx);

		tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
	}

	void set(int index) {
		set(index, 0, 0, size);
	}
	int sum(int l, int r, int x, int lx, int rx) {
		if (lx >= l && rx <= r)
			return tree[x];
		if (lx >= r || rx <= l)
			return 0;

		int mid = (rx + lx) / 2;
		return sum(l, r, 2 * x + 1, lx, mid) + sum(l, r, 2 * x + 2, mid, rx);
	}

	int sum(int l, int r) {
		return sum(l, r, 0, 0, size);
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// давайте пройдём по перестановке слева направо, заведём массив длины n + 1
	// и будем отмечать 1 те ячейки массива, номера которых уже встретили
	// тогда, сделав ДО на этом массиве, сможем отвечать на количество инверсий для очередного числа,
	// как сумма единиц на позициях [x+1..n], то есть сумма на подотрезке
	int n; cin >> n;
	int x;
	segtree ST;
	ST.init(n + 1);
	for (int i = 0; i < n; ++i) {
		cin >> x;
		cout << ST.sum(x + 1, n + 1) << ' ';
		ST.set(x);
	}
}
/*
Дана перестановка p из n элементов, найдите для каждого i число таких j, что j<i и p[j]>p[i]
*/
