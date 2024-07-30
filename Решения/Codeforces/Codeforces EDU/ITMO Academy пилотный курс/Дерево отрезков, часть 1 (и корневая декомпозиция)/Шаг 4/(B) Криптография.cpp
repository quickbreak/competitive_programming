#include<iostream>
#include<vector>

using namespace std;

struct matrix {
public:
	int el11 = 1, el12 = 0, el21 = 0, el22 = 1;
	matrix() = default;
};

int r;

matrix product(matrix a1, matrix a2) {
	matrix result;
	result.el11 = (a1.el11 * a2.el11 + a1.el12 * a2.el21) % r;
	result.el12 = (a1.el11 * a2.el12 + a1.el12 * a2.el22) % r;
	result.el21 = (a1.el21 * a2.el11 + a1.el22 * a2.el21) % r;
	result.el22 = (a1.el21 * a2.el12 + a1.el22 * a2.el22) % r;
	return result;
}

const matrix E;

struct segtree {
	vector<matrix>tree;
	int size = 1;

	void init(int n) {
		while (size < n)
			size *= 2;
		tree = vector<matrix>(2 * size - 1);
	}

	void build(vector<matrix>& a, int x, int lx, int  rx) {
		if (rx - lx == 1) {
			if (lx < a.size())
				tree[x] = a[lx];
			return;
		}
		int mid = (rx + lx) / 2;
		build(a, 2 * x + 1, lx, mid);
		build(a, 2 * x + 2, mid, rx);
		tree[x] = product(tree[2 * x + 1], tree[2 * x + 2]);
	}

	void build(vector<matrix>& a) {
		init(a.size());
		build(a, 0, 0, size);
	}

	matrix get_product(int l, int r, int x, int lx, int rx) {
		if (lx >= l && rx <= r)
			return tree[x];
		if (lx >= r || rx <= l)
			return E;
		int mid = (rx + lx) / 2;
		return product(get_product(l, r, 2 * x + 1, lx, mid), get_product(l, r, 2 * x + 2, mid, rx));
	}

	matrix get_product(int l, int r) {
		return get_product(l, r, 0, 0, size);
	}
};


int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m; cin >> r >> n >> m;
	vector<matrix>a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].el11 >> a[i].el12 >> a[i].el21 >> a[i].el22;
	}

	segtree ST;
	ST.build(a);

	int l, r;
	matrix A;
	while (--m >= 0) {
		cin >> l >> r;
		A = ST.get_product(l - 1, r);
		cout << A.el11 << ' ' << A.el12 << '\n' << A.el21 << ' ' << A.el22 << "\n\n";
	}
}