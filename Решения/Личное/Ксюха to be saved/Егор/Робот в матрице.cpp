#include <iostream>
#include <vector>

using namespace std;

int32_t main() {
	setlocale(0, "RU");
	int n, m; cin >> n >> m; // n строк, m столбцов
	vector a(n, vector<int>(m)); // исходная матрица
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	// робот в левом верхнем углу матрицы
	vector d(n, vector<int>(m));
	d[0][0] = a[0][0];

	vector path(n, vector<pair<int, int>>(m));
	path[0][0] = { -1, -1 };

	for (int j = 1; j < m; ++j) { // верхняя строка
		if (a[0][j] > a[0][j - 1])
		{
			d[0][j] = d[0][j - 1] + a[0][j];
			path[0][j] = { 0, j - 1 };
		}
		else
		{
			d[0][j] = d[0][j - 1] - a[0][j];
			path[0][j] = { 0, j - 1 };
		}
	}

	for (int i = 1; i < n; ++i) { // левый столбец
		if (a[i][0] > a[i - 1][0])
		{
			d[i][0] = d[i - 1][0] + a[i][0];
			path[i][0] = { i - 1, 0 };
		}
		else
		{
			d[i][0] = d[i - 1][0] - a[i][0];
			path[i][0] = { i - 1, 0 };
		}
	}

	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < m; ++j) {
			if (a[i][j] > a[i][j - 1])
			{
				d[i][j] = d[i][j - 1] + a[i][j];
				path[i][j] = { i, j - 1 };
			}
			else
			{
				d[i][j] = d[i][j - 1] - a[i][j];
				path[i][j] = { i, j - 1 };
			}

			if (a[i][j] > a[i - 1][j])
			{
				if (d[i - 1][j] + a[i][j] > d[i][j]) {
					d[i][j] = d[i - 1][j] + a[i][j];
					path[i][j] = { i - 1, j };

				}

			}
			else
			{
				if (d[i - 1][j] - a[i][j] > d[i][j]) {
					d[i][j] = d[i - 1][j] - a[i][j];
					path[i][j] = { i - 1, j };

				}
			}

		}

	}
	cout << "Максимальное значение: " << d[n - 1][m - 1] << '\n';
	cout << "Путь:\n";
	vector<int>res;
	auto p = path[n - 1][m - 1];
	int x = n - 1, y = m - 1;
	
	while (!(p.first == -1 && p.second == -1)) {
		res.push_back(a[x][y]);
		p = path[x][y];
		x = p.first;
		y = p.second;

	}
	for (int i = res.size() - 1; i >= 0; --i)
		cout << res[i] << ' ';
	cout << '\n';

	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < m; ++j) {
			if (a[i][j] > a[i][j - 1])
			{
				d[i][j] = d[i][j - 1] + a[i][j];
				path[i][j] = { i, j - 1};
			}
			else
			{
				d[i][j] = d[i][j - 1] - a[i][j];
				path[i][j] = { i, j - 1};
			}

			if (a[i][j] > a[i - 1][j])
			{
				if (d[i - 1][j] + a[i][j] < d[i][j]) {
					d[i][j] = d[i - 1][j] + a[i][j];
					path[i][j] = { i - 1, j };

				}
			}
			else
			{
				if (d[i - 1][j] - a[i][j] < d[i][j]) {
					d[i][j] = d[i - 1][j] - a[i][j];
					path[i][j] = { i - 1, j };

				}
			}

		}

	}
	cout << "Минимальное значение: " << d[n - 1][m - 1] << '\n';
	cout << "Путь:\n";
	res.clear();
	p = path[n - 1][m - 1];
	x = n - 1, y = m - 1;
	while (!(p.first == -1 && p.second == -1)) {
		res.push_back(a[x][y]);
		p = path[x][y];
		x = p.first;
		y = p.second;

	}
	for (int i = res.size() - 1; i >= 0; --i)
		cout << res[i] << ' ';
	cout << '\n';

}
/*
2 2
1 3
2 4

3 4
1 2 3 4
1 2 3 4
1 2 3 4
*/