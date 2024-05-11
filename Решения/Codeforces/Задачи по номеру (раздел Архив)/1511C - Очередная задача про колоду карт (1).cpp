#include <iostream>
#include <cassert>
#include <clocale>

using namespace std;


const int malo = -int(1e9);


struct node {
public:
	int value = malo;
	node* next = NULL;
	node(int value) :value(value), next(NULL) {};
	node() :value(malo), next(NULL) {};
};


struct linkedlist {
public:
	node* head;
	node* tail;
	linkedlist() : head(NULL), tail(NULL) {};

	// список пуст?
	bool empty() const {
		return head == NULL;
	};

	// добавить в конец элемент x
	void push_back(int value) {
		node* x = new node(value);
		// если это будет первый элемент (список пуст)
		if (this->empty()) {
			head = x;
			tail = x;
			return;
		}
		// если есть хотя бы один элемент
		tail->next = x;
		tail = x;
	};

	// добавить в начало элемент x
	void push_front(int value) {
		node* x = new node(value);
		// если это будет первый элемент (список пуст)
		if (this->empty()) {
			head = x;
			tail = x;
			return;
		}
		// если есть хотя бы один элемент
		x->next = head;
		head = x;
	};

	// вывести элементы списка
	void print() const {
		if (this->empty())
			return;
		node* current = head;
		while (current != NULL) {
			cout << current->value << ' ';
			current = current->next;
		}
		cout << '\n';
	};

	// поиск элемента по значению, первого по порядку
	int find(int value) const {
		if (this->empty())
			return 0;
		node* current = head;
		int cnt = 0;
		while (current != NULL) {
			++cnt;
			if (current->value == value) {
				return cnt;
			}
			current = current->next;
		}
	};

	// удаление элемента по значению, если такой есть, первого по порядку
	void erase(int value) {
		if (this->empty())
			return;
		// если первый подошёл
		node* pointer;
		if (head->value == value) {
			pointer = head;
			head = head->next;
			// если элемент был всего один
			if (head == NULL) {
				tail = head;
			}
			delete pointer;
			return;
		}
		node* previous = head;
		node* current = previous->next;
		// иначе
		while (current != NULL) {
			// если нашли значение
			if (current->value == value) {
				previous->next = current->next;
				// если это был крайний элемент
				if (previous->next == NULL) {
					tail = previous;
				}
				delete current;
				return;
			}
			previous = current;
			current = current->next;
		}
	};

	// чтение списка от пользователя
	void fill() {
		if (!this->empty()) {
			cout << "Список не пуст. Очистите его, или добавляйте элементы в конец\n";
			return;
		}
		assert(this->empty());
		cout << "Введите размер списка\n";
		int n; cin >> n;
		cout << "Введите список: " << n << " целых чисел\n";
		int val;
		while (--n >= 0) {
			cin >> val;
			this->push_back(val);
		}
	};

	// автоматически собранный список
	void fill_auto() {
		if (!this->empty()) {
			cout << "Список не пуст. Очистите его, или добавляйте элементы в конец\n";
			return;
		}
		assert(this->empty());
		int n = 10;
		cout << "Автособранный список (" << n << " элементов):\n";
		for (int i = 1; i <= n; ++i) {
			this->push_back(i);
			// cout << i << ' ';
		}
		// cout << '\n';
		this->print();
	};

};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q; cin >> n >> q;
	int x;
	linkedlist a;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		a.push_back(x);
	}
	while (--q >= 0) {
		cin >> x;
		cout << a.find(x) << ' ';
		a.erase(x);
		a.push_front(x);
	}
}