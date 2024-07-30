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

	void set(int index, int x, int lx, int rx) {
		if (rx - lx == 1) {
			tree[x] = 1;
			return;
		}
		int mid = (rx + lx) / 2;
		if (index < mid)
			set(index, 2 * x + 1, lx, mid);
		else
			set(index, 2 * x + 2, mid, rx);

		tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
	}

	void set(int index) {
		set(index, 0, 0, size);
	}

	int sum(int l, int r, int x, int lx, int rx) {
		if (lx >= l && rx <= r) {
			return tree[x];
		}
		if (lx >= r || rx <= l)
			return 0;
		int mid = (rx + lx) / 2;
		return (sum(l, r, 2 * x + 1, lx, mid) + sum(l, r, 2 * x + 2, mid, rx));
	}

	int sum(int l, int r) {
		return sum(l, r, 0, 0, size);
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	/*
	давайте построим дерево на массиве длины 2*n (изначально просто заполним нулями),
	и, когда встретили правую границу отрезка х, будет устанавливать 1 в его левую границу.
	Тогда ответ для каждого отрезка - это количество единиц между его левой и правой границей.
	* Ведь если левая граница какого-то отрезка y помечена 1, то этот отрезок уже закрылся.
	* А раз левая граница y внутри нашего отрезка х, то и правая, очевидно, тоже
	*/
	int n; cin >> n;
	vector<int>a(2 * n);
	for (int i = 0; i < 2 * n; ++i) {
		cin >> a[i];
	}
	// построим дерево на исходном массиве
	segtree ST;
	ST.init(2 * n);
	vector<int>meet(n + 1);
	vector<pair<int, int>>res(n + 1);
	for (int i = 0; i < 2 * n; ++i) {
		++meet[a[i]];
		if (meet[a[i]] == 1) {
			res[a[i]].first = i;
		}
		if (meet[a[i]] == 2) {
			res[a[i]].second = ST.sum(res[a[i]].first, i);
			ST.set(res[a[i]].first);
		}
	}
	/*for (auto& [first, cnt] : res) 
		cout << cnt << ' ';*/
	for (int i = 1; i <= n; ++i)
		cout << res[i].second << ' ';
}

/*
Дан массив из 2*n чисел, каждое число от 1 до n в нем встречается ровно два раза. 
Будем говорить, что отрезок y вложен в отрезок x, если оба вхождения числа y находятся между вхождениями числа x. 
Найдите для каждого отрезка i количество отрезков, которые в него вложены.
*/
