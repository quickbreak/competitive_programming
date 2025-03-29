#include <iostream>


using namespace std;


int main() {
	int k, n;
	cin >> k >> n;
	int Lena = 0, Sasha = 0, x;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		if ((x % 5 == 0) && (x % 3 != 0)) {
			++Lena;
		}
		else if ((x % 3 == 0) && (x % 5 != 0)) {
			++Sasha;
		}
		if (Lena == k) {
			cout << "Lena";
			return 0;
		}
		else if (Sasha == k) {
			cout << "Sasha";
			return 0;
		}
	}
	if (Lena > Sasha) {
		cout << "Lena";
	}
	else if (Sasha > Lena) {
		cout << "Sasha";
	}
	else {
		cout << "Draw";
	}
}
