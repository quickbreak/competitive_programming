#include <bits/stdc++.h>
#include <random>

#ifndef __ALLOCATOR_HPP__
#define __ALLOCATOR_HPP__
namespace algos {
namespace allocator {
namespace Memory {
    char buf[150*1024*1024];
    int64_t ptr{150*1024*1024};
    void* malloc(uint64_t cnt) {
        ptr-=cnt;
        assert(ptr>=0);
        return (void*)(buf+ptr);
    }
}
 
template <class T>
struct Allocator {
    using value_type = T;
    Allocator () = default;
    template <class U> constexpr Allocator (const Allocator <U>&) noexcept {}
    T* allocate(std::size_t n) { return (T*)(Memory::malloc(n*sizeof(T))); }
    void deallocate(T*, std::size_t) noexcept { }
};
 
template <class T, class U> bool operator==(const Allocator<T>&, const Allocator<U>&) { return true; }
template <class T, class U> bool operator!=(const Allocator<T>&, const Allocator<U>&) { return false; }
 
template<class T>
using Vec = std::vector<T,Allocator<T>>;
template<class T>
using List = std::list<T,Allocator<T>>;
template<class T, class C = std::less<T>>
using Set = std::set<T,C,Allocator<T>>;
template<class T, class C = std::less<T>>
using Multiset = std::multiset<T,C,Allocator<T>>;
template<class K, class V, class C = std::less<K>>
using Map = std::map<K,V,C,Allocator<std::pair<const K, V>>>;
} // namespace allocator
} // namespace algos
#endif // __ALLOCATOR_HPP__

using namespace algos::allocator;

using namespace std;


struct SegmentTree {
public:
	vector<Multiset<pair<int, int>>>tree_;
	int size_ = 1;
	vector<int>lazy_propagation_; // ленивое до, lazy_propagation_[i] = х 
	// значит, что в поддереве с вершиной в i были удалены все элементы y: y<=x
	vector<int> a_;

	void init(int n) {
		while (size_ < n) {
			size_ <<= 1;
		}
		tree_.assign(2 * size_ - 1, Multiset<pair<int, int>>());
		lazy_propagation_.assign(2 * size_ - 1, 0);
		a_.assign(2 * size_ - 1, 0);
	}

	void build(int n) {
		init(n);
	}

	void push(int x) { // продавливание
		/*от листьев не вызывается*/
		while (!tree_[2 * x + 1].empty() && tree_[2 * x + 1].begin()->first <= lazy_propagation_[2 * x + 1]) {
			tree_[2 * x + 1].erase(tree_[2 * x + 1].begin());
			a_[tree_[2 * x + 1].begin()->second] = 0;
		}
		while (!tree_[2 * x + 2].empty() && tree_[2 * x + 2].begin()->first <= lazy_propagation_[2 * x + 2]) {
			tree_[2 * x + 2].erase(tree_[2 * x + 2].begin());
			a_[tree_[2 * x + 2].begin()->second] = 0;
		}
		lazy_propagation_[2 * x + 1] = lazy_propagation_[2 * x + 2] = lazy_propagation_[x];
		lazy_propagation_[x] = 0; // через эту вершину продавили
	}

	void set(int pos, int new_value, int old_value, int x, int lx, int rx) {
		tree_[x].erase({ old_value, pos });
		tree_[x].insert({ new_value, pos });

		if (rx - lx == 1) { // лист
			return;
		}

		push(x); // обновили вершины, в которые идём
		
		int mid = (rx + lx) / 2;
		if (pos < mid)
			set(pos, new_value, old_value, 2 * x + 1, lx, mid);
		else
			set(pos, new_value, old_value, 2 * x + 2, mid, rx);

		return;
	}

	void set(int pos, int new_value) {
		set(pos, new_value, a_[pos], 0, 0, size_);
		a_[pos] = new_value;
		return;
	}

	int attack(int l, int r, int p, int x, int lx, int rx) {
		if (lx >= r || rx <= l) { // поддерево с корнем в x полностью не входит в искомый подотрезок
			return 0;
		}
		if (lx >= l && rx <= r) { // поддерево с корнем в x полностью входит в искомый подотрезок
			int cnt = 0;
			while (!tree_[x].empty() && tree_[x].begin()->first <= p) {
				// если это нынешнее удаление, а не старое
				if (tree_[x].begin()->first == a_[tree_[x].begin()->second]) {
					++cnt;
					a_[tree_[x].begin()->second] = 0;
				}
				tree_[x].erase(tree_[x].begin());
			}

			lazy_propagation_[x] = max(lazy_propagation_[x], p); // запоминаем, что из поддерева с корнем в х нужно удалить все элементы <= p
			
			return cnt;
		}

		push(x); // обновили вершины, в которые идём

		int mid = (rx + lx) / 2;
		return attack(l, r, p, 2 * x + 1, lx, mid) + attack(l, r, p, 2 * x + 2, mid, rx);
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
