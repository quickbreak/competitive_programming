#include <iostream>
#include <vector>


using namespace std;


struct node {
	int value = int(1e9)+7;
	int cnt = 1;
	node() = default;
};


const node defaultnode;

node minnode(node first, node second) {
	node result;
	if (first.value < second.value)
		result = first;
	else if (second.value < first.value)
		result = second;
	else {
		result.value = first.value;
		result.cnt = first.cnt + second.cnt;
	}
	return result;
}

struct segtree {
	vector<node>tree;
	int size = 1;

	void init(int n) {
		while (size < n)
			size *= 2;
		tree.assign(2 * size - 1, defaultnode);
	}

	void build(vector<int>& a, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < a.size())
				tree[x].value = a[lx];
			return;
		}
		int mid = (rx + lx) / 2;
		build(a, 2 * x + 1, lx, mid);
		build(a, 2 * x + 2, mid, rx);
		tree[x] = minnode(tree[2 * x + 1], tree[2 * x + 2]);
	}

	void build(vector<int>& a) {
		init(a.size());
		build(a, 0, 0, size);
	}

	void set(int index, int value, int x, int lx, int rx) {
		if (rx - lx == 1) {
			tree[x].value = value;
			tree[x].cnt = 1;
			return;
		}

		int mid = (rx + lx) / 2;
		if (index < mid)
			set(index, value, 2 * x + 1, lx, mid);
		else
			set(index, value, 2 * x + 2, mid, rx);

		tree[x] = minnode(tree[2 * x + 1], tree[2 * x + 2]);
	}

	void set(int index, int value) {
		set(index, value, 0, 0, size);
	}

	node getmincnt(int l, int r, int x, int lx, int rx) {
		if (lx >= l && rx <= r) {
			return tree[x];
		}
		if (lx >= r || rx <= l) {
			return defaultnode;
		}
		int mid = (rx + lx) / 2;
		node left = getmincnt(l, r, 2 * x + 1, lx, mid);
		node right = getmincnt(l, r, 2 * x + 2, mid, rx);
		return minnode(left, right);
	}

	node getmincnt(int l, int r) {
		return getmincnt(l, r, 0, 0, size);
	}
};


int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m; cin >> n >> m;
	vector<int>a(n);
	for (int& x : a)
		cin >> x;

	segtree ST;
	ST.build(a);
	int operation, x, y;
	while (--m >= 0) {
		cin >> operation >> x >> y;
		if (operation == 1)
			ST.set(x, y);
		else {
			node p = ST.getmincnt(x, y);
			cout << p.value << ' ' << p.cnt << '\n';
		}
			
	}
}
