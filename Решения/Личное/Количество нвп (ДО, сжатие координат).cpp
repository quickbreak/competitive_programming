#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


long long mod = 1LL*(int(1e9)+7);

struct node {
	int max_len;
	long long cnt;

	node() : // think of default
		max_len(0),
		cnt(1LL)
	{}

	node(pair<int, long long>p) :
		max_len(p.first),
		cnt(p.second)
	{}
};

const node node_default(make_pair(0, 1LL));

struct segtree {
	vector<node>tree;
	int size = 1;

	node maxnode(node node_1, node node_2) {
		node result;
		if (node_1.max_len > node_2.max_len) {
			result.max_len = node_1.max_len;
			result.cnt = node_1.cnt;
		}
		else if (node_2.max_len > node_1.max_len) {
			result.max_len = node_2.max_len;
			result.cnt = node_2.cnt;
		}
		else {
			result.max_len = node_1.max_len;
			result.cnt = (result.max_len == 0 ? 1LL : (node_1.cnt + node_2.cnt) % mod);
		}

		return result;
	}

	void init(int n) {
		while (size < n) size *= 2;
		tree.assign(2 * size - 1, node_default);
	}
	
	void build(vector<int>& b, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (x < b.size()) {
				tree[x].max_len = 0;
				tree[x].cnt = 1;
			}
			return;
		}
		int mid = (lx + rx) / 2;
		build(b, 2 * x + 1, lx, mid);
		build(b, 2 * x + 2, mid, rx);
		
		tree[x] = maxnode(tree[2 * x + 1], tree[2 * x + 2]);
	}

	void build(vector<int>& b) {
		init(b.size());
		// build(b, 0, 0, size);
	}

	void set(int index, node value, int x, int lx, int rx) {
		if (rx - lx == 1) { // сюда заходим единожды
			tree[x] = maxnode(tree[x], value);
			return;
		}
		int mid = (lx + rx) / 2;
		if (index < mid)
			set(index, value, 2 * x + 1, lx, mid);
		else
			set(index, value, 2 * x + 2, mid, rx);
		
		// keep tree
		tree[x] = maxnode(tree[2 * x + 1], tree[2 * x + 2]);
	}

	void set(int index, node value) {
		set(index, value, 0, 0, size);
	}

	node get_max(int l, int r, int x, int lx, int rx) {
		//if (rx - lx == 1) { // мы сюда лишний раз не зайдём?
		//	return tree[x];
		//}

		if (lx >= r || rx <= l)
			return node_default;
		if (lx >= l && rx <= r) {
			return tree[x];
		}

		int mid = (lx + rx) / 2;
		node leftmax = get_max(l, r, 2 * x + 1, lx, mid);
		node rightmax = get_max(l, r, 2 * x + 2, mid, rx);

		return maxnode(leftmax, rightmax);

	}

	node get_max(int l, int r) {
		return get_max(l, r, 0, 0, size);
	}
};

using ll = long long;

ll binpow(ll base, ll p)
{
	if (p == 0)
		return 1;
	if (p == 1)
		return base;
	if (p % 2 == 0)
	{
		ll polovina = binpow(base, p / 2);
		return polovina * polovina % mod;
	}
	else
	{
		ll pminus = binpow(base, (p - 1) / 2);
		ll res = pminus * pminus % mod;
		return res * base % mod;
	}
}

int main() {
	int n; cin >> n; // >=1
	// int n = 100000;
	vector<int>a(n);
	for (int& x : a)
		cin >> x;
	/*int num = 1;
	for (int i = 0; i < 100000; i+=2) {
		a[i] = num;
		a[i + 1] = num;
		++num;
	}
	cout << binpow(2, 100000 / 2) << '\n';*/

	vector<int>b = a;
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());

	for (int& x : a)
		x = int(lower_bound(b.begin(), b.end(), x) - b.begin());

	segtree ST;
	ST.build(b);
	for (int& x : a) {
		node prev_max = ST.get_max(0, x);
		++prev_max.max_len;
		ST.set(x, prev_max);
	}

	cout << ST.get_max(0, ST.size).cnt;

	// mod ты не сделал

}

/*
5
1 2 3 4 5
--1

6
1 1 2 2 3 3
--8
*/