#include <iostream>
#include <vector>


using namespace std;


struct node {
	long long maxsum = 0LL;
	long long prefsum = 0LL;
	long long suffsum = 0LL;
	long long sum = 0LL;
	node() :
		maxsum(0LL),
		prefsum(0LL),
		suffsum(0LL),
		sum(0LL)
	{};
};


node max(const node& first, const node& second) {
	node result;
	
	// максимальная сумма на подотрезке текущего отрезка - либо максимальная и макс.сумм левой и правой частей
	result.maxsum = max(first.maxsum, second.maxsum);
	// либо макс.суффикс левой части + макс.префикс правой 
	result.maxsum = max(result.maxsum, first.suffsum + second.prefsum);
	// макс.префикс отрезка - либо макс.префикс левой половины, либо вся левая половина + макс.префикс правой
	result.prefsum = max(first.prefsum, first.sum + second.prefsum);
	// макс.суффикс отрезка - либо макс.суффикс правой половины, либо вся правая половина + макс.суффикс правой
	result.suffsum = max(second.suffsum, second.sum + first.suffsum);
	result.sum = first.sum + second.sum;

	return result;
}


node defaultnode = {};


struct segtree {
	vector<node>tree;
	int size = 1;

	void init(int n) {
		while (size < n)
			size *= 2;
		tree.assign(2 * size - 1, defaultnode);
	}

	void build(vector<long long>& a, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < a.size()) {
				// подотрезок может выбирать пустой. 
				// Тогда максимальная сумма на отрезке может быть равна 0
				tree[x].maxsum = max(a[lx], 0LL);
				tree[x].prefsum = max(a[lx], 0LL);
				tree[x].suffsum = max(a[lx], 0LL);
				tree[x].sum = a[lx];
			}
			return;
		}
		int mid = (rx + lx) / 2;
		build(a, 2 * x + 1, lx, mid);
		build(a, 2 * x + 2, mid, rx);
		tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
	}

	void build(vector<long long>& a) {
		init(a.size());
		build(a, 0, 0, size);
	}

	void set(int index, long long value, int x, int lx, int rx) {
		if (rx - lx == 1) {
			// подотрезок может выбирать пустой. 
			// Тогда максимальная сумма на отрезке может быть равна 0
			tree[x].maxsum = max(value, 0LL);
			tree[x].prefsum = max(value, 0LL);
			tree[x].suffsum = max(value, 0LL);
			tree[x].sum = value;

			return;
		}
		int mid = (rx + lx) / 2;
		if (index < mid)
			set(index, value, 2 * x + 1, lx, mid);
		else
			set(index, value, 2 * x + 2, mid, rx);
		tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
	}

	void set(int index, long long value) {
		set(index, value, 0, 0, size);
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Задача: найти подотрезок массива максимальной суммы (и вывести эту сумму)
	int n, m; cin >> n >> m;
	vector<long long>a(n);
	for (long long& x : a)
		cin >> x;
	segtree ST;
	ST.build(a);
	cout << ST.tree[0].maxsum << '\n';
	int index;
	long long value;
	while (--m >= 0) {
		cin >> index >> value;
		ST.set(index, value);
		cout << ST.tree[0].maxsum << '\n';
	}
}

/*
5 2
5 -4 4 3 -5
4 3
3 -1
--8
11
7

4 2
-2 -1 -5 -4
1 3
3 2
--0
3
3

1 3
-5
0 0
0 -800
0 900
--0
0
0
900
*/
