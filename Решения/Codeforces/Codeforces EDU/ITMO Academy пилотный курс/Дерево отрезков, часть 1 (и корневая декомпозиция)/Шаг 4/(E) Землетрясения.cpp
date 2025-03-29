#include <iostream>
#include <vector>
#include <random>


using namespace std;


struct SegmentTree {
public:
	vector<int>tree_; // минимум в поддереве
	int size_ = 1;
	const int kInf = (int)1e9 + 7;

	void init(int n) {
		while (size_ < n) {
			size_ <<= 1;
		}
		tree_ = vector<int>(2 * size_ - 1, kInf);
	}

	void build(int n) {
		init(n);
	}

	void set(int pos, int new_value, int x, int lx, int rx) {
		if (rx - lx == 1) {
			tree_[x] = new_value;
			return;
		}

		int mid = (rx + lx) / 2;
		if (pos < mid)
			set(pos, new_value, 2 * x + 1, lx, mid);
		else
			set(pos, new_value, 2 * x + 2, mid, rx);

		tree_[x] = min(tree_[2 * x + 1], tree_[2 * x + 2]);
	}

	void set(int pos, int new_value) {
		set(pos, new_value, 0, 0, size_);
	}

	int attack(int l, int r, int p, int x, int lx, int rx) {
		if (lx >= r || rx <= l) { // поддерево с корнем в x полностью не входит в искомый подотрезок
			return 0;
		}
		// частично или полностью поддерво входит в искомый подотрезок
		if (tree_[x] > p) // ни одни элемент поддерева не подойдёт
			return 0;
		// сколько-то элементов поддерева подойдёт, надо удалить их из следующих вершин
		if (rx - lx == 1) { // следующих вершин нет
			if (tree_[x] <= p) {
				tree_[x] = kInf;
				return 1;
			}
			else {
				return 0;
			}
		}
		// следующие вершины есть
		int mid = (rx + lx) / 2;
		int left_cnt = attack(l, r, p, 2 * x + 1, lx, mid);
		int right_cnt = attack(l, r, p, 2 * x + 2, mid, rx);

		tree_[x] = min(tree_[2 * x + 1], tree_[2 * x + 2]);

		return left_cnt + right_cnt;
	}

	int attack(int l, int r, int p) {
		return attack(l, r, p, 0, 0, size_);
	}

};


struct Query {
	int type, l, r, index, value, p;
};

vector<int> slow(int n, int q, const vector<Query>& queries) {
	vector<int> a(n);
	Query query;
	vector<int>res;
	for (int i = 0; i < q; ++i) {
		query = queries[i];
		if (query.type == 1) {
			a[query.index] = query.value;
		}
		else if (query.type == 2) {
			int cnt = 0;
			for (int j = query.l; j < query.r; ++j) {
				if (a[j] <= query.p && a[j] > 0) {
					++cnt;
					a[j] = 0;
				}
			}
			res.push_back(cnt);
		}
	}
	return res;
}


vector<int> wrong(int n, int q, const vector<Query>& queries) {
	SegmentTree segment_tree;
	segment_tree.build(n);
	Query query;
	vector<int>res;
	for (int i = 0; i < q; ++i) {
		query = queries[i];
		if (query.type == 1) {
			segment_tree.set(query.index, query.value);
		}
		else if (query.type == 2) {
			res.push_back(segment_tree.attack(query.l, query.r, query.p));
		}
	}
	return res;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, q; cin >> n >> q;
	vector<Query>queries(q);
	Query query;
	for (int i = 0; i < q; ++i) {
		cin >> query.type;
		if (query.type == 1) {
			cin >> query.index;
			cin >> query.value;;
		}
		else if (query.type == 2) {
			cin >> query.l;
			cin >> query.r;
			cin >> query.p;
		}
		queries[i] = query;
	}
	vector<int> wrong_res = wrong(n, q, queries);
	for (int& x : wrong_res)
		cout << x << '\n';


	return 0;


	/*
	основная идея:
	до этого в ДО при запросах на отрезках мы, дойдя до вершины, которая полностью входит в искомый полуинтервал, 
	останавливались, возвращаясь с частью ответа.
	Здесь мы не можем этого сделать, потому что в запросе нам нужно не только узнать что-то на отрезке, 
	но и обновить все вершины из полуинтервала (удалить, обнулить в данном случае). А значит мы должны и спуститься 
	до каждой из таких вершин.
	В предыдущих задачах на ДО мы не могли себе позволить такого. Но в этой массив изначально пуст.
	На операцию установки значения (set) мы тратим O(log(n)) действий и на удаление столько же (каждое значение удаляется единожды).
	Выходит q * log(n) операций?
	*/



	int t = 1000;
	while (t-- > 0) {
		random_device rd;   // non-deterministic generator
		mt19937 gen(rd());  // to seed mersenne twister.
		uniform_int_distribution<> distn(1, 10);
		uniform_int_distribution<> distq(1, 11);
		int n = distn(gen);
		int q = distq(gen);
		uniform_int_distribution<> distlrind(0, n - 1);
		uniform_int_distribution<> disttype(1, 2);
		uniform_int_distribution<> distpvalue(1, 10);
		vector<Query>queries(q);
		for (int i = 0; i < q; ++i) {
			Query query;
			query.type = disttype(gen);
			if (query.type == 1) {
				query.index = distlrind(gen);
				query.value = distpvalue(gen);
			}
			else if (query.type == 2) {
				query.l = distlrind(gen);
				query.r = distlrind(gen);
				if (query.l == query.r)
					continue;
				if (query.l > query.r)
					swap(query.l, query.r);
				query.p = distpvalue(gen);
			}
			queries[i] = query;
		}
		vector<int> slow_res = slow(n, q, queries);
		vector<int> wrong_res = wrong(n, q, queries);
		if (slow_res != wrong_res) {
			cout << n << ' ' << q << '\n';
			for (int i = 0; i < q; ++i) {
				cout << queries[i].type << ' ';
				if (queries[i].type == 1) {
					cout << queries[i].index << ' ' << queries[i].value << '\n';
				} else {
					cout << queries[i].l << ' ' << queries[i].r << ' ' << queries[i].p << '\n';
				}
			}
			cout << '\n';
			for (int& x : slow_res)
				cout << x << ' ';
			cout << '\n';
			for (int& x : wrong_res)
				cout << x << ' ';
			cout << '\n';
			break;
		}
		else if (t % 100 == 0)
			cout << "same\n";
	}
}

/*
5 9
1 0 3
1 2 5
2 0 4 3
1 1 4
1 2 7
2 1 3 6
1 3 8
1 4 4
2 0 5 10
---
1
1
3

5 4
1 3 5
2 0 1 6
2 2 4 3
2 2 4 7
---
0
0
1

5 4
1 3 3
1 2 10
2 0 3 4
2 1 4 3
---
0
1
*/
