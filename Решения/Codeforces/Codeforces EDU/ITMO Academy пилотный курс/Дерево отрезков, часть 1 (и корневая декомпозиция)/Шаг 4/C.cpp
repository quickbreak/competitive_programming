#include<iostream>
#include<vector>

using namespace std;

#define useless ios_base::sync_with_stdio(false); cin.tie(NULL);

struct node
{
	int cnt[41]{};
};

struct segment_tree
{
private:
	vector<node>tree;
	int size = 1;
public:
	void init(int n)
	{
		while (size < n)
			size *= 2;
		tree = vector<node>(2 * size - 1);
	}

	void build(const vector<int>& a, int x, int lx, int rx)
	{
		if (rx - lx == 1)
		{
			if (lx < a.size())
			{
				++tree[x].cnt[a[lx]];
			}
			return;
		}
		int mid = (rx + lx) / 2;
		build(a, 2 * x + 1, lx, mid);
		build(a, 2 * x + 2, mid, rx);

		for (int i = 0; i < 41; ++i)
		{
			tree[x].cnt[i] = tree[2 * x + 1].cnt[i] + tree[2 * x + 2].cnt[i];
		}
	}

	void build(const vector<int>& a)
	{
		init(a.size());
		build(a, 0, 0, size);
	}

	void get_cnt(vector<int>& res_cnt, int l, int r, int x, int lx, int rx)
	{
		if (lx >= l && rx <= r)
		{
			for (int i = 0; i < 41; ++i)
				res_cnt[i] += tree[x].cnt[i];

			return;
		}
		if (lx >= r || rx <= l)
			return;

		int mid = (rx + lx) / 2;
		get_cnt(res_cnt, l, r, 2 * x + 1, lx, mid);
		get_cnt(res_cnt, l, r, 2 * x + 2, mid, rx);
	}

	int get_cnt(int l, int r)
	{
		vector<int>res_cnt(41);
		get_cnt(res_cnt, l - 1, r, 0, 0, size);

		int inversion_count = 0;
		long long prefsum = 0;
		for (int i = 0; i < 41; ++i)
		{
			inversion_count += res_cnt[i] * prefsum;
			prefsum += res_cnt[i];
		}
		return inversion_count;
	}

	void change(int index, int value, int x, int lx, int rx)
	{
		if (rx - lx == 1)
		{
			for (int i = 0; i < 41; ++i)
				tree[x].cnt[i] = 0;

			tree[x].cnt[value] = 1;

			return;
		}
		int mid = (rx + lx) / 2;
		if (index < mid)
			change(index, value, 2 * x + 1, lx, mid);
		else
			change(index, value, 2 * x + 2, mid, rx);

		for (int i = 0; i < 41; ++i)
		{
			tree[x].cnt[i] = tree[2 * x + 1].cnt[i] + tree[2 * x + 2].cnt[i];
		}
	}

	void change(int index, int value)
	{
		change(index - 1, value, 0, 0, size);
	}
};


int main()
{
	useless;

	int n, q; cin >> n >> q;
	vector<int>a(n);
	for (int& x : a)
		cin >> x;
	segment_tree ST;
	ST.build(a);
	int type, x, y;
	while (--q >= 0)
	{
		cin >> type >> x >> y;
		if (type == 1)
		{
			cout << ST.get_cnt(x, y) << '\n';
		}
		else
		{
			ST.change(x, y);
		}
	}
}

/*


*/