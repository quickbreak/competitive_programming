#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;


int main() {
	int n; cin >> n;
	vector<int>parent(n + 1);
	for (int i = 2; i <= n; ++i)
		cin >> parent[i];

	int number = n;
	vector<int>res = { number };
	while (number != 1) {
		number = parent[number];
		res.push_back(number);
	}
	reverse(res.begin(), res.end());
	for (int& x : res)
		cout << x << ' ';
}