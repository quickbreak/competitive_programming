#include <bits/stdc++.h>

using namespace std;

int main() {
	int t; cin >> t;
	int n;
	while (t-- > 0) {
		cin >> n;
		cout << n / 4 + (n % 4 == 2) << '\n';
	}
}