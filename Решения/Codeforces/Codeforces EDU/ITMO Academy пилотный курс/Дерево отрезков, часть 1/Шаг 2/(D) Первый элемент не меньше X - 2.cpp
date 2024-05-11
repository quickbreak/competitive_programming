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

	int lower_bound(int value, int l,  int x, int lx, int rx) {
		if (rx - lx == 1) {
			return lx;
		}
		int mid = (rx + lx) / 2;
		int resleft = -1;
		// если максимум в правом сыне >= value и отрезок закончится после левой границы l, идём в него 
		if (tree[2 * x + 1] >= value && l < mid) {
			resleft = lower_bound(value, l, 2 * x + 1, lx, mid);
		}
		// иначе, если в левом сыне есть подходящее значение, идём в него
		if (resleft == -1 && tree[2 * x + 2] >= value)
			return lower_bound(value, l, 2 * x + 2, mid, rx);
		else return resleft;
	}

	int lower_bound(int value, int l) {
		// если все элементы массива меньше value
		if (tree[0] < value)
			return -1;
		return lower_bound(value, l, 0, 0, size);
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
	int operation, index, newvalue, value, l;
	while (--m >= 0) {
		cin >> operation;
		if (operation == 1) {
			cin >> index >> newvalue;
			ST.set(index, newvalue);
		}
		else {
			cin >> value >> l;
			cout << ST.lower_bound(value, l) << '\n';
		}
	}
}

/*
давайте будем хранить в каждой вершине максимальное значение на полуинтервале, за который она отвечает
*/
