#include <iostream>
#include <vector>

#define useless ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

struct segtree {

	// листья дерева - элементы исходного массива (и дополняющие нули)
	vector<long long>tree;
	int size = 1;

	void init(int array_len) {
		// дополняем длину до степени двойки
		while (size < array_len) {
			size *= 2;
		}
		tree.assign(2 * size - 1, 0);
	}
	// х - индекс в tree, 
	// [lx, rx) - полуинтервал исходного (но дополненного) массива,
	// который находится ниже узла x
	void build(const vector<int>& a, int x, int lx, int rx) {
		if (rx - lx == 1) {	// если достигли листа
			if (lx < a.size()) { // и в листе хранится элемент исходного массива (а не дополняющий 0)
				tree[x] = a[lx];
			}
			return;
		}
		// иначе спускаемся в поддеревья (в левого и правого сыновей)
		int mid = (lx + rx) / 2;
		build(a, 2 * x + 1, lx, mid);
		build(a, 2 * x + 2, mid, rx);
		// не забываем заполнять узлы дерева
		tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
	}

	void build(const vector<int>& a) {
		init(a.size());
		build(a, 0, 0, size);
	}

	void set(int pos, int value, int x, int lx, int rx) {
		if (rx - lx == 1) { // пришли к листу, где хранится элемент a[pos]
			tree[x] = value;
			return;
		}
		// идём всегда либо в левого сына, либо в правого: другого не дано, дерево бинарное
		// так что никогда не зайдём в ненужный лист (не pos)
		int mid = (lx + rx) / 2;
		if (pos < mid) { // искомый элемент в левом поддереве
			set(pos, value, 2 * x + 1, lx, mid);
		}
		else { // искомый элемент в правом поддереве
			set(pos, value, 2 * x + 2, mid, rx);
		}

		// не забываем перезаполнять узлы, через которые прошли
		tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
	}

	void set(int pos, int value) {
		set(pos, value, 0, 0, size);
	}

	long long sum(int l, int r, int x, int lx, int rx) {

		if (lx >= r || rx <= l) { // отрезок, за который отвечает вершина х, ПОЛНОСТЬЮ НЕ входит в нужный
			return 0;
		}
		if (lx >= l && rx <= r) { // отрезок, за который отвечает вершина х, ПОЛНОСТЬЮ входит в нужный
			return tree[x];
		}
		// отрезок, за который отвечает вершина х, ЧАСТИЧНО входит в нужный
		int mid = (lx + rx) / 2;
		long long leftsum = sum(l, r, 2 * x + 1, lx, mid);
		long long rightsum = sum(l, r, 2 * x + 2, mid, rx);
		return leftsum + rightsum;
	}

	long long sum(int l, int r) {
		return sum(l, r, 0, 0, size);
	}
};


int main() {
	useless;

	int n, m; cin >> n >> m;
	vector<int>a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	segtree ST;
	ST.build(a);
	int c; // command
	int l, r; // границы, на которых искать сумму
	int pos, value; // элементу на позиции pos будем присваивать значение value
	while (--m >= 0) {
		cin >> c;
		if (c == 1) { // операция изменения элемента
			cin >> pos >> value;
			ST.set(pos, value);
		}
		else { // возврат суммы на полуинтервале [l, r)
			cin >> l >> r;
			cout << ST.sum(l, r) << '\n';
		}
	}
}
