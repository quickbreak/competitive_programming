#include <iostream>
#include <vector>


using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n, m; cin >> t;
	while (--t >= 0) {
		// через сколько МИНИМАЛЬНО запросов хотя бы на одном отрезке единиц станет больше, чем нулей?
		cin >> n >> m;
		vector<pair<int, int>>segment(m); // массив отрезков (заданных парами [l, r])
		for (int i = 0; i < m; ++i) {
			cin >> segment[i].first >> segment[i].second;
			--segment[i].first;
			--segment[i].second;
		}

		vector<int>a(n, 0); // изначально а - массив из n нулей
		vector<int>prefcnt(n + 1); // количество единиц на префиксе (она же сумма)
		int q; cin >> q;
		vector<int>query;
		int x;
		while (--q >= 0) { // запрос a[x] = 1
			cin >> x;
			query.push_back(x - 1);
		}

		int l = -1, r = query.size(), m;
		bool ok = false;
		while (r - l > 1) { // бинпоиск по количеству запросов
			ok = false;
			m = (r + l) / 2;
			// расставляем единицы
			for (int i = 0; i <= m; ++i) {
				a[query[i]] = 1;
			}
			// считаем префсуммы
			for (int i = 0; i < n; ++i) {
				prefcnt[i + 1] = prefcnt[i] + a[i];
			}

			for (auto p : segment) {
				// количество единиц больше нулей?
				if ((prefcnt[p.second + 1] - prefcnt[p.first]) >
					(p.second - p.first + 1 - (prefcnt[p.second + 1] - prefcnt[p.first]))) {
					ok = true;
					break;
				}
			}
			if (ok)
				r = m;
			else l = m;

			// не забываем откат
			a.assign(n, 0);
			prefcnt.assign(n + 1, 0);
		}
		if (r < query.size()) {
			cout << r + 1 << '\n';
		}
		else cout << "-1\n";

	}
}

/*
input:
6
5 5
1 2
4 5
1 5
1 3
2 4
5
5
3
1
2
4
4 2
1 1
4 4
2
2
3
5 2
1 5
1 5
4
2
1
3
4
5 2
1 5
1 3
5
4
1
2
3
5
5 5
1 5
1 5
1 5
1 5
1 4
3
1
4
3
3 2
2 2
1 3
3
2
3
1
--output:
3
-1
3
3
3
1
*/