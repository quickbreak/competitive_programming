#include<iostream>
#include<vector>


using namespace std;


struct node {
	node* left = NULL;
	node* right = NULL;
};

// префиксное-дерево/бор (бинарный)
struct prefix_tree {
	node* root = new node();

	void add_number(node* vertex, int number, int next_bit_number) {
		if (next_bit_number == -1) {
			return;
		}
		if (((1 << next_bit_number) & number) != 0) { // если в следующем бите у числа 1
			if (vertex->right == NULL)
				vertex->right = new node();
			add_number(vertex->right, number, next_bit_number - 1);
		}
		else {
			if (vertex->left == NULL)
				vertex->left = new node();
			add_number(vertex->left, number, next_bit_number - 1);
		}
	}

	void add_number(int number) {
		add_number(root, number, 17);
	}

	void build(vector<int>& a) {
		int n = a.size();
		for (int i = 0; i < n; ++i) {
			add_number(a[i]);
		}
	}

	int get_max(int number, int max_number, node* vertex, int next_bit_number) {
		if (next_bit_number == -1) {
			return (number ^ max_number);
		}
		if (((1 << next_bit_number) & number) != 0) { // если в следующем бите у числа нужен бы 0 (у number там 1)
			if (vertex->left != NULL) // если подходящие числа есть
				return get_max(number, max_number, vertex->left, next_bit_number - 1);
			else
				return get_max(number, max_number + (1 << next_bit_number), vertex->right, next_bit_number - 1);
		}
		else { // в следующем бите у числа нужна бы 1 (у number там 0)
			if (vertex->right != NULL) // если подходящие числа есть
				return get_max(number, max_number + (1 << next_bit_number), vertex->right, next_bit_number - 1);
			else
				return get_max(number, max_number, vertex->left, next_bit_number - 1);
		}
	}

	int get_max(int number) { // максимальный ксор с number
		return get_max(number, 0, root, 17);
	}

	int get_min(int number, int min_number, node* vertex, int next_bit_number) {
		if (next_bit_number == -1) {
			return (number ^ min_number);
		}
		if (((1 << next_bit_number) & number) != 0) { // если в следующем бите у числа нужна бы 1 (у number там 1)
			if (vertex->right != NULL) // если подходящие числа есть
				return get_min(number, min_number + (1 << next_bit_number), vertex->right, next_bit_number - 1);
			else
				return get_min(number, min_number, vertex->left, next_bit_number - 1);
		}
		else { // в следующем бите у числа нужен бы 0 (у number там 0)
			if (vertex->left != NULL) // если подходящие числа есть
				return get_min(number, min_number, vertex->left, next_bit_number - 1);
			else
				return get_min(number, min_number + (1 << next_bit_number), vertex->right, next_bit_number - 1);

		}
	}

	int get_min(int number) { // минимальный ксор с number
		return get_min(number, 0, root, 17);
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t, l, r; cin >> t;
	while (--t >= 0) {
		cin >> l >> r;
		vector<int>a(r - l + 1);
		for (int& x : a)
			cin >> x;

		prefix_tree bor;
		bor.build(a);

		int left = int(1e9), right = 0, x;
		for (int i = l; i <= r; ++i) {
			x = a[0] ^ i;
			if (bor.get_max(x) == r && bor.get_min(x) == l) {
				cout << x << '\n';
				break;
			}
		}
	}
	
}

/*
раз изначально а был перестановкой (все числа различны),
то и после ксора массива с числом х все числа различны.
Тогда достаточно посмотреть, чтобы минимальный обратный ксор был равен l, а максимальный - r.
Переберём x от ? до ? и найдём подходящий.
Границы. 
массив [l..r]
Давайте возьмём любой элемент финального массива а (например, первый).
Поксорим a[1] со всеми числами [l..r]. Что мы получим?
l - r + 1 значений, среди которых одно - обязательно ответ х.
Стало быть, перебрать нам нужно эти r-l+1 значений и найти среди них подходящий!
*/