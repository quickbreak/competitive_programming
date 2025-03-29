#include<iostream>
#include<vector>
#include<string>


using namespace std;


#define isz(x) (int)x.size()
#define remin(x, y) x = min(x, y)
#define remax(x, y) x = max(x, y)


void invert(vector<string>& a) {
	int n = isz(a);
	if (n == 0)
		return;
	int m = isz(a[0]);
	vector<string>b(m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			b[j] += a[i][j];
		}
	}
	a = b;
}


void delete_empty(vector<string>& a) {
	int n = isz(a);
	if (n == 0)
		return;
	int m = isz(a[0]);
	bool delete_first = true;
	for (int j = 0; j < m; ++j) {
		if (a[0][j] == '#')
			delete_first = false;;
	}
	bool delete_last = false;
	if (n > 1) {
		delete_last = true;
		for (int j = 0; j < m; ++j) {
			if (a[n - 1][j] == '#')
				delete_last = false;
		}
	}
	vector<string>b;
	if (delete_first) {
		if (delete_last) {
			for (int i = 1; i < n - 1; ++i)
				b.push_back(a[i]);
		}
		else {
			for (int i = 1; i < n; ++i)
				b.push_back(a[i]);
		}
	}
	else if (delete_last) {
		for (int i = 0; i < n - 1; ++i)
			b.push_back(a[i]);
	}
	else {
		for (int i = 0; i < n; ++i)
			b.push_back(a[i]);
	}

	a = b;
}


void delete_duplicates(vector<string>& a) {
	int n = isz(a);
	if (n == 0)
		return;
	int m = isz(a[0]);
	vector<string>b = { a[0] };
	for (int i = 1; i < n; ++i) { // удаляем повторяющиеся строки (ну почти все)
		if (a[i] != b[isz(b) - 1]) {
			b.push_back(a[i]);
		}
	}
	a = b;
}


int main() {
	int n; cin >> n;
	vector<string>a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	
	delete_duplicates(a);  // удаляем повторяющиеся строки
	invert(a);  // транспонируем матрицу
	delete_duplicates(a);  // чтобы удалить повторяющиеся столбцы
	invert(a);

	delete_empty(a);  // удаляем пустые строки
	invert(a);  // транспонируем матрицу
	delete_empty(a);  // чтобы удалить пустые столбцы
	invert(a);

	string ostatok = "";
	for (int i = 0; i < isz(a); ++i) {
		ostatok += a[i] + "\n";
	}
	if (ostatok == "#\n")
		cout << "I";
	else if (ostatok == "###\n#.#\n###\n")
		cout << "O";
	else if (ostatok == "##\n#.\n##\n")
		cout << "C";
	else if (ostatok == "#.\n##\n")
		cout << "L";
	else if (ostatok == "#.#\n###\n#.#\n")
		cout << "H";
	else if (ostatok == "###\n#.#\n###\n#..\n")
		cout << "P";
	else cout << "X";
}