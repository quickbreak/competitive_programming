#include <iostream>

using namespace std;

long long summa(long long x) {
	if (x == 1)
		return x;
	return x + summa((x % 2 == 0) ? (x / 2) : ((x - 1) / 2));
}

int main() {
	int t; cin >> t;
	while (--t >= 0) {
		long long n;  cin >> n;
		cout << summa(n) << '\n';
	}
}