#include <iostream>
#include <vector>


using namespace std;


struct Node {
	long long maxx = -(long long)2e9 - 7;
	long long minx = (long long)2e9+7;
	long long res = -(long long)2e9-7;
	void print() {
		cerr << maxx << ' ' << minx << ' ' << res;
	}
};


long long max(long long a, long long b, long long c) {
	a = max(a, b);
	return max(a, c);
}


struct segtree1 {
public:
	vector<Node>tree;
	int size = 1;
	
	void init(int n) {
		while (size < n) {
			size *= 2;
		}
		tree = vector<Node>(2 * size - 1);
	}

	void build(const vector<long long>& a, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < a.size()) {
				tree[x].maxx = tree[x].minx = a[lx] - (lx + 1);
				tree[x].res = 0;

			}
			return;
		}

		int m = (lx + rx) / 2;
		build(a, 2 * x + 1, lx, m);
		build(a, 2 * x + 2, m, rx);

		tree[x].maxx = max(tree[2 * x + 1].maxx, tree[2 * x + 2].maxx);
		tree[x].minx = min(tree[2 * x + 1].minx, tree[2 * x + 2].minx);
		tree[x].res = max(tree[2 * x + 1].res, tree[2 * x + 2].res, tree[2 * x + 2].maxx - tree[2 * x + 1].minx);
		//cerr << lx << '-' << rx << ": ";
		//tree[2 * x + 1].print();
		//cerr << "    ";
		//tree[2 * x + 2].print();
		//cerr << "      ";
		//tree[x].print();
		//cerr << '\n';
	}

	long long build(const vector<long long>&a) {
		init(a.size());
		build(a, 0, 0, size);

		return tree[0].res;
	}

	void set(int pos, long long value, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx == pos) {
				tree[x].maxx = tree[x].minx = value - (lx + 1);
				tree[x].res = 0;
			}
			return;
		}

		int m = (rx + lx) / 2;
		if (pos < m) {
			set(pos, value, 2 * x + 1, lx, m);
		}
		else {
			set(pos, value, 2 * x + 2, m, rx);
		}

		tree[x].maxx = max(tree[2 * x + 1].maxx, tree[2 * x + 2].maxx);
		tree[x].minx = min(tree[2 * x + 1].minx, tree[2 * x + 2].minx);
		tree[x].res = max(tree[2 * x + 1].res, tree[2 * x + 2].res, tree[2 * x + 2].maxx - tree[2 * x + 1].minx);
		//cerr << lx << '-' << rx << ": ";
		//tree[2 * x + 1].print();
		//cerr << "    ";
		//tree[2 * x + 2].print();
		//cerr << "      ";
		//tree[x].print();
		//cerr << '\n';
	}

	long long set(int pos, long long value) {
		set(pos, value, 0, 0, size);

		return tree[0].res;
	}
};

struct segtree2 {
public:
	vector<Node>tree;
	int size = 1;

	void init(int n) {
		while (size < n) {
			size *= 2;
		}
		tree = vector<Node>(2 * size - 1);
	}

	void build(const vector<long long>& a, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < a.size()) {
				tree[x].maxx = tree[x].minx = a[lx] + (lx + 1);
				tree[x].res = 0;

			}
			return;
		}

		int m = (lx + rx) / 2;
		build(a, 2 * x + 1, lx, m);
		build(a, 2 * x + 2, m, rx);

		tree[x].maxx = max(tree[2 * x + 1].maxx, tree[2 * x + 2].maxx);
		tree[x].minx = min(tree[2 * x + 1].minx, tree[2 * x + 2].minx);
		tree[x].res = max(tree[2 * x + 1].res, tree[2 * x + 2].res, tree[2 * x + 1].maxx - tree[2 * x + 2].minx);
		//cerr << lx << '-' << rx << ": ";
		//tree[2 * x + 1].print();
		//cerr << "    ";
		//tree[2 * x + 2].print();
		//cerr << "      ";
		//tree[x].print();
		//cerr << '\n';
	}

	long long build(const vector<long long>& a) {
		init(a.size());
		build(a, 0, 0, size);

		return tree[0].res;
	}

	void set(int pos, long long value, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx == pos) {
				tree[x].maxx = tree[x].minx = value + (lx + 1);
				tree[x].res = 0;
			}
			return;
		}

		int m = (rx + lx) / 2;
		if (pos < m) {
			set(pos, value, 2 * x + 1, lx, m);
		}
		else {
			set(pos, value, 2 * x + 2, m, rx);
		}

		tree[x].maxx = max(tree[2 * x + 1].maxx, tree[2 * x + 2].maxx);
		tree[x].minx = min(tree[2 * x + 1].minx, tree[2 * x + 2].minx);
		tree[x].res = max(tree[2 * x + 1].res, tree[2 * x + 2].res, tree[2 * x + 1].maxx - tree[2 * x + 2].minx);
		//cerr << lx << '-' << rx << ": ";
		//tree[2 * x + 1].print();
		//cerr << "    ";
		//tree[2 * x + 2].print();
		//cerr << "      ";
		//tree[x].print();
		//cerr << '\n';
	}

	long long set(int pos, long long value) {
		set(pos, value, 0, 0, size);

		return tree[0].res;
	}
};


int32_t main() {
	int t; cin >> t;
	int n, q, p, v;
	while (t-- > 0) {
		cin >> n >> q;
		vector<long long>a(n);
		for (long long& y : a)
			cin >> y;

		segtree1 ST1;
		segtree2 ST2;
		cout << max(ST1.build(a), ST2.build(a)) << '\n';

		while (q-- > 0) {
			cin >> p >> v;
			--p;
			cout << max(ST1.set(p, v), ST2.set(p, v)) << '\n';
		}
	}
}