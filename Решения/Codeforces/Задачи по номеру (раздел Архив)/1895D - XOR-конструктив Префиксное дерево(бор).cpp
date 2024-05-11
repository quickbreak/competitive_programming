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
		for (int i = 0; i < a.size(); ++i) {
			add_number(a[i]);
		}
	}

	int get_max(int b0, int max_number, node* vertex, int next_bit_number) {
		if (next_bit_number == -1) {
			return (b0 ^ max_number);
		}
		if (((1 << next_bit_number) & b0) != 0) { // если в следующем бите у числа нужен бы 0 (у b0 там 1)
			if (vertex->left != NULL) // если подходящие числа есть
				return get_max(b0, max_number, vertex->left, next_bit_number - 1);
			else
				return get_max(b0, max_number + (1 << next_bit_number), vertex->right, next_bit_number - 1);
		}
		else { // в следующем бите у числа нужна бы 1 (у b0 там 0)
			if (vertex->right != NULL) // если подходящие числа есть
				return get_max(b0, max_number + (1 << next_bit_number), vertex->right, next_bit_number - 1);
			else
				return get_max(b0, max_number, vertex->left, next_bit_number - 1);
		}
	}

	int get_max(int b0) { // максимальный ксор среди b[0]^prefix_xor[i] для всех i
		return get_max(b0, 0, root, 17);
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<int>a(n - 1), prefix_xor(n);
	for (int i = 0; i < n - 1; ++i) {
		cin >> a[i];
		prefix_xor[i + 1] = prefix_xor[i] ^ a[i];
	}

	prefix_tree bor;
	bor.build(prefix_xor);

	int resb0 = -1;
	for (int b0 = 0; b0 <= n - 1; ++b0) { // переберём b[0], и возьмём первый подошедший
		if (bor.get_max(b0) <= n - 1) { // если максимальный ксор не превосходит n-1, то никакой не превосходит
			resb0 = b0;
			break;
		}
	}
	
	cout << resb0 << ' ';
	for (int i = 1; i < n; ++i)
		cout << (resb0 ^ prefix_xor[i]) << ' ';
	
	/*
	b[i] = b[i-1]^a[i - 1]
	b[i + 1] = b[i] ^ a[i] = b[i - 1] ^ a[i - 1] ^ a[i]
	b[i + 2] = b[i + 1] ^ a[i + 1] = b[i - 1] ^ a[i - 1] ^ a[i] ^ a[i + 1]
	b[j] = b[0] ^ prefxor[j]
	*/

	/*
	поскольку гарантируется, что существует корректная перестановка b
	(все элементы различны),
	то все prefxor[j] обязаны быть различными.
	Тогда остаётся проверить только то, что максимальный b[0]^prefxor[j] <= n-1
	*/
}