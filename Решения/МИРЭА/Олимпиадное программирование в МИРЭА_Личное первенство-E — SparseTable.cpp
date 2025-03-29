#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <set>


using namespace std;


#define all(x) x.begin(), x.end()


struct BST {
public:
	struct Node {
	public:
		int val_; // значение
		Node* left_ = nullptr; // указатель на левого сына
		Node* right_ = nullptr; // указатель на правого сына
		int ind_ = -1; // индекс в первоначальном массиве
		Node(int val, int ind) :
			val_(val),
			left_(nullptr),
			right_(nullptr),
			ind_(ind)
		{};
	};
	Node* root_ = nullptr;

	// Вставка очередного элемента в дерево
	void insert(vector<int>& res, int val, int ind) {
		Node* node = new Node(val, ind);
		Node* curr = root_;
		if (curr == nullptr) {
			root_ = node;
			return;
		}
		while (true) { // Ищем место, куда должно встать новое число, и ставим туда
			if (node->val_ < curr->val_) { // Новое число должно быть левее рассматриваемого
				if (curr->left_ == nullptr) { // У рассматриваемой вершины нет левого сына -> мы нашли место для новой вершины
					curr->left_ = node;
					res[ind] = curr->val_;
					break;
				}
				else { // У рассматриваемой вершины есть левый сын -> спускаемся дальше
					curr = curr->left_;
				}
			}
			else if (node->val_ > curr->val_) { // Новое число должно быть правее рассматриваемого
				if (curr->right_ == nullptr) { // У рассматриваемой вершины нет правого сына -> мы нашли место для новой вершины
					curr->right_ = node;
					res[ind] = curr->val_;
					break;
				}
				else { // У рассматриваемой вершины есть правый сын -> спускаемся дальше
					curr = curr->right_;
				}
			}
			else { // В дереве есть элемент, равный вставляемому по значению (но в этой задаче такого не может быть)		
				break;
			}
		}
	}
};


vector<int> slow(const vector<pair<int, int>>& a) { // a - массив в изначальном состоянии
	BST bst;
	vector<int>res(a.size());
	for (const auto& p : a) { // Строим дерево в явном виде
		bst.insert(res, p.first, p.second);
	}
	return res;
}


struct SparseTable {
public:
	// {индекс в изначальном массиве, он минимизируется; индекс в отсортированном массиве}
	vector<vector<pair<int, int>>>spt_;

	int log2n_;

#ifdef _MSC_VER
	int __lg(int n) const {
		std::cerr << "MSVC\n";
		return std::log2(n);
	}
#endif // !_MSC_VER

	void init(int n) {
		log2n_ = __lg(n);
		spt_ = vector(n, vector<pair<int, int>>(log2n_ + 1));
	}

	void build(const vector<pair<int, int>>& a) {
		int n = a.size();
		init(n);
		for (int i = 0; i < n; ++i) // Подотрезки длины 1
			spt_[i][0] = { a[i].second, i };
		for (int pow2 = 1; pow2 <= log2n_; ++pow2) { // pow2 - Показатель степени двойки
			for (int i = 0; i + (1 << pow2) <= n; ++i) { // Пока с началом с позиции i в массиве найдётся подотрезок длины 2**pow2
				// длина 2x <- min(f(i, x), f(i+x, x)), где f(a, b) = минимум на подотрезке длины b начиная с позиции a
				// spt_[i][pow2] = min(spt_[i][pow2 - 1], spt_[i + (1 >> (pow2 - 1))][pow2 - 1]);
				spt_[i][pow2] = spt_[i][pow2 - 1] < spt_[i + (1 << (pow2 - 1))][pow2 - 1] ? spt_[i][pow2 - 1] : spt_[i + (1 << (pow2 - 1))][pow2 - 1];
			}
		}
	}

	const int kInf_ = (int)1e9 + 7;
	// элемент на отрезке [l, r), раньше всех стоящий в первоначальном массиве
	// возвращается {индекс этого элемента в первоначальном массиве, индекс этого элемента в отсортированном массиве}
	pair<int, int> GetMin(int l, int r) const {
		// идея: f на отрезке длины len = min(минимум на отрезке длины log2(len) с началом в l, минимум на промежутке длины log2(len) с концом в r)
		int log2 = __lg(r - l);
		// return min(spt_[l][log2], spt_[r - (1 << log2)][log2]);
		return ((spt_[l][log2] < spt_[r - (1 << log2)][log2]) ? spt_[l][log2] : spt_[r - (1 << log2)][log2]);
	}
};


// l, r, dad_ind - индексы в отсортированном массиве
void FindSons(const vector<pair<int, int>>& a, int l, int r, int dad, int dad_ind, vector<int>& res, const SparseTable& spt) {
	if (r - l <= 1)
		return;
	// Решение задачи: если мы знаем значение корня дерева, 
	// то его левый сын - это элемент, который меньше него и стоит раньше остальных в первоначальном массиве
	// правый определяется аналогично
	// Так, зная корень всего дерева, рекурсивно находим детей корней всех поддеревьев
	if (dad_ind - l >= 1) {
		auto [firstly, sorted] = spt.GetMin(l, dad_ind);
		res[firstly] = dad;
		FindSons(a, l, dad_ind, a[sorted].first, sorted, res, spt);
	}
	if (r - (dad_ind + 1) >= 1) {
		auto [firstly, sorted] = spt.GetMin(dad_ind + 1, r);
		res[firstly] = dad;
		FindSons(a, dad_ind + 1, r, a[sorted].first, sorted, res, spt);
	}
}


vector<int> wrong(vector<pair<int, int>>& a) { // a - массив в первоначальном состоянии
	int n = a.size();
	int root_val = a[0].first;
	sort(all(a));
	int root_ind;
	for (int i = 0; i < n; ++i) {
		if (a[i].first == root_val) {
			root_ind = i;
			break;
		}
	}
	vector<int>res(n);
	SparseTable spt;
	spt.build(a);
	FindSons(a, 0, n, root_val, root_ind, res, spt);
	for (int i = 1; i < n; ++i) {
		cout << res[i] << ' ';
	}
	return res;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int number;
	cin >> number;
	vector<pair<int, int>>arr(number);
	for (int x, i = 0; i < number; ++i) {
		cin >> x;
		arr[i] = { x, i };
	}
	wrong(arr);

	return 0;

	random_device rd;   // non-deterministic generator
	mt19937 gen(rd());  // to seed mersenne twister.
	uniform_int_distribution<> distn(1, 10);
	uniform_int_distribution<> distai(1, 10);
	int n = distn(gen);
	for (int t = 0; t < 1'000; ++t) {
		int n = distn(gen);
		vector<pair<int, int>>a; // значение, индекс в изначальном массиве
		set<int>st;
		for (int x, i = 0; i < n; ++i) {
			x = distai(gen);
			if (!st.contains(x)) {
				a.push_back({ x, i });
				st.insert(x);
			}
		}
		n = a.size();
		for (int i = 0; i < n; ++i)
			a[i].second = i;
		vector a_copy(a);
		vector<int> slow_res = slow(a);
		vector<int> wrong_res = wrong(a);
		if (slow_res != wrong_res) {
			cout << n << '\n';
			for (const auto& p : a_copy) {
				cout << p.first << ' ';
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
10
10 5 7 9 2 1 4 8 3 6
  10 5 7 5 2 2 9 4 7
*/

/*
5
10 9 5 3 2
0 10 9 5 3
0 10 3 9 3
*/
