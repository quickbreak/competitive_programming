#include<iostream>
#include<vector>


using namespace std;


#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


struct segment_tree
{
public:
	struct Node
	{
	public:
		vector<long long> cnt_ = vector<long long>(41);
		long long inversions_count_ = 0;
		Node(vector<long long> cnt, long long inversions_count) :
			cnt_(std::move(cnt)),
			inversions_count_(inversions_count)
		{};
		Node() = default;
	};
	vector<Node>tree_;
	int size_ = 1;
	Node help_node = Node(vector<long long>(41), 0LL); // вспомогательная нейтральная нода


	void init(int n)
	{
		while (size_ < n)
			size_ *= 2;
		tree_ = vector<Node>(2 * size_ - 1);
	}

	void build(const vector<int>& a, int x, int lx, int rx)
	{
		if (rx - lx == 1)
		{
			if (lx < a.size())
			{
				++tree_[x].cnt_[a[lx]];
			}
			return;
		}
		int mid = (rx + lx) / 2;
		build(a, 2 * x + 1, lx, mid);
		build(a, 2 * x + 2, mid, rx);

		for (int i = 0; i < 41; ++i) // перекинуть количества элементов
		{
			tree_[x].cnt_[i] = tree_[2 * x + 1].cnt_[i] + tree_[2 * x + 2].cnt_[i];
		}
		// количество инверсий: это сумма количеств инверсий в правом и левом сыновьях + 
		// + количество инверсий, которые образуются в результате слияния двух половин массива
		// для каждого элемента x из правой части появляется suff_sum элементов левее него, которые больше него
		tree_[x].inversions_count_ = tree_[2 * x + 1].inversions_count_ + tree_[2 * x + 2].inversions_count_;
		long long suff_sum = 0LL;
		for (int i = 0; i < 41; ++i) {
			suff_sum = 0LL;
			for (int j = i + 1; j < 41; ++j)
				suff_sum += tree_[2 * x + 1].cnt_[j];
			tree_[x].inversions_count_ += 1LL * tree_[2 * x + 2].cnt_[i] * suff_sum;
		}
	}

	void build(const vector<int>& a)
	{
		init(a.size());
		build(a, 0, 0, size_);
	}

	Node get_inversions_cnt(int l, int r, int x, int lx, int rx)
	{
		if (lx >= r || rx <= l) // полностью не входит в искомый подотрезок
			return help_node; 
		if (lx >= l && rx <= r) { // полностью входит
			return tree_[x];
		}

		int mid = (rx + lx) / 2;
		auto left = get_inversions_cnt(l, r, 2 * x + 1, lx, mid);
		auto right = get_inversions_cnt(l, r, 2 * x + 2, mid, rx);

		vector<long long>cnt(41);
		long long inversions_count = left.inversions_count_ + right.inversions_count_;
		long long suff_sum = 0LL;
		for (int i = 0; i < 41; ++i) {
			suff_sum = 0LL;
			for (int j = i + 1; j < 41; ++j)
				suff_sum += left.cnt_[j];
			inversions_count += 1LL * right.cnt_[i] * suff_sum;
		}

		for (int i = 0; i < 41; ++i)
		{
			cnt[i] = left.cnt_[i] + right.cnt_[i];
		}

		return Node(cnt, inversions_count);
	}

	long long get_inversions_cnt(int l, int r)
	{
		return get_inversions_cnt(l - 1, r, 0, 0, size_).inversions_count_;
	}

	void set(int index, int value, int x, int lx, int rx)
	{
		if (rx - lx == 1)
		{
			for (int i = 0; i < 41; ++i)
				tree_[x].cnt_[i] = 0;

			tree_[x].cnt_[value] = 1;

			return;
		}

		int mid = (rx + lx) / 2;
		if (index < mid)
			set(index, value, 2 * x + 1, lx, mid);
		else
			set(index, value, 2 * x + 2, mid, rx);

		for (int i = 0; i < 41; ++i)
		{
			tree_[x].cnt_[i] = tree_[2 * x + 1].cnt_[i] + tree_[2 * x + 2].cnt_[i];
		}

		tree_[x].inversions_count_ = tree_[2 * x + 1].inversions_count_ + tree_[2 * x + 2].inversions_count_;
		long long suff_sum = 0LL;
		for (int i = 0; i < 41; ++i) {
			suff_sum = 0LL;
			for (int j = i + 1; j < 41; ++j)
				suff_sum += tree_[2 * x + 1].cnt_[j];
			tree_[x].inversions_count_ += 1LL * tree_[2 * x + 2].cnt_[i] * suff_sum;
		}
	}

	void set(int index, int value)
	{
		set(index - 1, value, 0, 0, size_);
	}
};


int main()
{
	fastIO;

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
			cout << ST.get_inversions_cnt(x, y) << '\n';
		}
		else
		{
			ST.set(x, y);
		}
	}
}

/*
7 6
1 2 3 6 5 4 19
1 1 3
1 2 5
1 2 4
2 2 8
1 1 6
1 1 3
---
0
1
0
7
1
*/
