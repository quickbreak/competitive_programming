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

	void build(int n, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx > 0 && lx < n)
				tree[x] = 1;
			return;
		}
		int mid = (rx + lx) / 2;
		build(n, 2 * x + 1, lx, mid);
		build(n, 2 * x + 2, mid, rx);

		tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
	}

	void build(int n) {
		init(n);
		build(n, 0, 0, size);
	}

	void set(int index, int x, int lx, int rx) {
		if (rx - lx == 1) {
			tree[x] = 0;
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

	int get(int k, int x, int lx, int rx) {
		if (rx - lx == 1) {
			return lx;
		}

		int mid = (rx + lx) / 2;
		if (k < tree[2 * x + 2])
			return get(k, 2 * x + 2, mid, rx);
		else
			return get(k - tree[2 * x + 2], 2 * x + 1, lx, mid);
	}

	int get(int k) {
		return get(k, 0, 0, size);
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// давайте заведём массив длины n + 1, заполним его единицами
	// тогда, сделав ДО на этом массиве, 
	// сможем, пойдя по массиву а справа налево, 
	// получать число, больше которого из не взятых есть k чисел, 
	// как k-УЮ ЕДИНИЦУ с конца
	int n; cin >> n;
	int k;
	segtree ST;
	ST.build(n + 1);
	vector<int>a(n), res(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = n - 1; i >= 0; --i) {
		k = a[i];
		int number = ST.get(k);
		res[i] = number;
		ST.set(number);
	}
	for (int& number : res)
		cout << number << ' ';
}
/*
Была перестановка p из n элементов, 
для каждого i записали число a[i] — число таких j, что j < i и p[j] > p[i]. 
Восстановите по заданным a[i] исходную перестановку.
*/
