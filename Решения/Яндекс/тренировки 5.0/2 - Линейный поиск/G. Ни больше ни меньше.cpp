#include <iostream>
#include <vector>

using namespace std;

int32_t main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// минимально возможное количество отрезков, 
	// чтобы каждое число было не меньше длины 
	// отрезка, которому оно принадлежит

	// короче, минимальный элемент на отрезке >= длина массива
	int t; cin >> t;
	int n;
	while (--t >= 0) {
		cin >> n;
		int min_el = int(1e9), l = 0, x, ans = 0;
		vector<int>res; // длины отрезков
		for (int r = 0; r < n; ++r) {
			cin >> x;
			min_el = min(min_el, x); // минимальный элемент на отрезке
			if (min_el < r - l + 1) { // меньше длины массива?
				res.push_back(r - l); // запомнили длину очередного отрезка
				++ans; // увеличили количество отрезков
				l = r; // левую границу отрезка подвинули
				min_el = x; // х - первый элемент нового отрезка
			}
		}
		cout << ans + 1 << '\n';
		res.push_back(n - 1 - l + 1);
		for (int cnt : res)
			cout << cnt << ' ';
		cout << '\n';
	}

}
/*
3
5
1 3 3 3 2
#ans:
3
1 3 1

16
1 9 8 7 6 7 8 9 9 9 9 9 9 9 9 9
#ans:
3
1 6 9

7
7 2 3 4 3 2 7
#ans:
3
2 3 2
*/