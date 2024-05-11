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

	void set(int index, int value, int x, int lx, int rx) {
		if (rx - lx == 1) {
			tree[x] = value;
			return;
		}
		int mid = (rx + lx) / 2;
		if (index < mid)
			set(index, value, 2 * x + 1, lx, mid);
		else
			set(index, value, 2 * x + 2, mid, rx);

		tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
	}

	void set(int index, int value) {
		set(index, value, 0, 0, size);
	}

	int turningsum(int l, int r, int x, int lx, int rx) {
		if (lx >= l && rx <= r) {
			return tree[x];
		}
		if (lx >= r || rx <= l) {
			return 0;
		}
		int mid = (rx + lx) / 2;
		return turningsum(l, r, 2 * x + 1, lx, mid) + turningsum(l, r, 2 * x + 2, mid, rx);
	}

	int turningsum(int l, int r) {
		return turningsum(l, r, 0, 0, size);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m; cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (i % 2 == 1)
			a[i] *= -1;
	}

	segtree ST;
	ST.build(a);

	cin >> m;
	int command;
	while(--m >= 0) {
		cin >> command;
		if (command == 0) {
			int index, value; cin >> index >> value;
			--index;
			if (index % 2 == 0)
				ST.set(index, value);
			else
				ST.set(index, -value);
		}
		else {
			int l, r; cin >> l >> r;
			--l;
			if (l % 2 == 0)
				cout << ST.turningsum(l, r) << '\n';
			else
				cout << -ST.turningsum(l, r) << '\n';
		}
	}
}