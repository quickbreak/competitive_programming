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

	void build(vector<int>& a, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < a.size())
				tree[x] = a[lx];
			return;
		}
		int mid = (rx + lx) / 2;
		build(a, 2 * x + 1, lx, mid);
		build(a, 2 * x + 2, mid, rx);
		tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
	}

	void build(vector<int>& a) {
		init(a.size());
		build(a, 0, 0, size);
	}

	void set(int index, int newvalue, int x, int lx, int rx) {
		if (rx - lx == 1) {
			tree[x] = newvalue;
			return;
		}
		int mid = (rx + lx) / 2;
		if (index < mid)
			set(index, newvalue, 2 * x + 1, lx, mid);
		else
			set(index, newvalue, 2 * x + 2, mid, rx);

		tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
	}

	void set(int index, int newvalue) {
		set(index, newvalue, 0, 0, size);
	}

	int lower_bound(int value, int x, int lx, int rx) {
		if (rx - lx == 1) {
			return lx;
		}
		int mid = (rx + lx) / 2;
		// если максимум в правом сыне >= value, идём в него 
		if (tree[2 * x + 1] >= value) {
			return lower_bound(value, 2 * x + 1, lx, mid);
		}
		// иначе - в левого
		else return lower_bound(value, 2 * x + 2, mid, rx);
	}

	int lower_bound(int value) {
		// если все элементы массива меньше value
		if (tree[0] < value)
			return -1;
		return lower_bound(value, 0, 0, size);
	}
};


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	vector<int>a(n);
	for (int& x : a)
		cin >> x;
	segtree ST;
	ST.build(a);
	int operation, index, newvalue, value;
	while (--m >= 0) {
		cin >> operation;
		if (operation == 1) {
			cin >> index >> newvalue;
			ST.set(index, newvalue);
		}
		else {
			cin >> value;
			cout << ST.lower_bound(value) << '\n';
		}
	}
}

/*
давайте будем хранить в каждой вершине максимальное значение на полуинтервале, за который она отвечает
*/
