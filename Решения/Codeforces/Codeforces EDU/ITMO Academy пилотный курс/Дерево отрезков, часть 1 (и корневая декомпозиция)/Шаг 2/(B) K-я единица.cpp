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
		tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
	}

	void build(vector<int>& a) {
		init(a.size());
		build(a, 0, 0, size);
	}

	void set(int index, int x, int lx, int rx) {
		if (rx - lx == 1) {
			tree[x] = (1 + tree[x]) % 2;
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

	int find(int k, int x, int lx, int rx) {
		if (rx - lx == 1) {
			return lx;
		}
		int mid = (rx + lx) / 2;
		// если в правом сыне >= k единиц, идём в него 
		if (tree[2 * x + 1] > k) {
			return find(k, 2 * x + 1, lx, mid);
		}
		// иначе - в левого
		else return find(k - tree[2 * x + 1], 2 * x + 2, mid, rx);
	}

	int find(int k) {
		return find(k, 0, 0, size);
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
	int operation, index, k;
	while (--m >= 0) {
		cin >> operation;
		if (operation == 1) {
			cin >> index;
			ST.set(index);
		}
		else {
			cin >> k;
			cout << ST.find(k) << '\n';
		}
	}
}

/*
давайте будем хранить в каждой вершине, сколько единиц на полуинтервале, за который она отвечает
*/
