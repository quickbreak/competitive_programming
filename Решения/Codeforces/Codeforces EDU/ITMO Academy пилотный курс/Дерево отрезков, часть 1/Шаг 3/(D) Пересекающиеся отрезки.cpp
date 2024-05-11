#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct segtree {
	vector<int>tree;
	int size = 1;

	void init(int n) {
		while (size < n)
			size *= 2;
		tree.assign(2 * size - 1, 0);
	}

	void set(int index, int value, int x, int lx, int rx) {
		if (rx - lx == 1) {
			tree[x] = value;
			return;
		}
		int mid = (rx + lx) / 2;
		if (index < mid)
			set(index, value, 2 * x + 1, lx, mid);
		else
			set(index, value, 2 * x + 2, mid, rx);

		tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
	}

	void set(int index, int value) {
		set(index, value, 0, 0, size);
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

	void clear() {
		for (int i = 0; i < 2 * size - 1; ++i)
			tree[i] = 0;
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	/*
	Давайте научимся сначала считать количество отрезков, которые пересекаются с нашим своей левой границей.
	давайте построим дерево на массиве длины 2*n (изначально просто заполним нулями),
	и, когда встретили левую границу отрезка х, будет устанавливать туда 1. 
	Когда встретили правую - возвращаем в левую границу 0.
	Тогда ответ для каждого отрезка - это количество единиц между его левой и правой границей.
	* Ведь если левая граница какого-то отрезка y помечена 1, то левая граница внутри нашего отрезка, 
	* а его правая граница ещё не встречалась.
	
	Отлично. А теперь развернём массив а, и пройдём по нему с теми же действиями.
	Выйдет, что мы посчитали количество отрезков, которые с нашим пересекается правыми границами.
	*/
	int n; cin >> n;
	vector<int>a(2 * n);
	for (int i = 0; i < 2 * n; ++i) {
		cin >> a[i];
	}

	segtree ST;
	ST.init(2 * n);
	vector<int>meet(n + 1);
	vector<pair<int, int>>res(n + 1);
	for (int i = 0; i < 2 * n; ++i) {
		++meet[a[i]];
		if (meet[a[i]] == 1) {
			ST.set(i, 1);
			res[a[i]].first = i;
		}
		if (meet[a[i]] == 2) {
			res[a[i]].second = ST.sum(res[a[i]].first + 1, i);
			ST.set(res[a[i]].first, 0);
		}
	}

	reverse(a.begin(), a.end());
	ST.clear();
	meet.assign(n + 1, 0);
	for (int i = 0; i < 2 * n; ++i) {
		++meet[a[i]];
		if (meet[a[i]] == 1) {
			ST.set(i, 1);
			res[a[i]].first = i;
		}
		if (meet[a[i]] == 2) {
			res[a[i]].second += ST.sum(res[a[i]].first + 1, i);
			ST.set(res[a[i]].first, 0);
		}
	}
	/*for (auto& [first, cnt] : res)
		cout << cnt << ' ';*/
	for (int i = 1; i <= n; ++i)
		cout << res[i].second << ' ';
}

/*
Дан массив из 2*n чисел, каждое число от 1 до n в нем встречается ровно два раза. 
Будем говорить, что отрезок y пересекается с отрезком x, 
если ровно одно вхождение числа y находятся между вхождениями числа x. 
Найдите для каждого отрезка i, сколько есть отрезков, которые с ним пересекаются.
*/
