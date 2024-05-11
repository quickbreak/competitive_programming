#include <iostream>
#include <vector>

using namespace std;
// периметр вырезанной фигуры
int main() {
	// использована клетка (i, j) или нет?
	vector color(10, vector<int>(10));
	int n, x, y;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		// --x, --y;
		color[x][y] = 1;
	}
	// изначально у каждой клетки по 4 строоны
	int ans = 4 * n;
	// понтовая итерация по списку :)
	for (int i : {1, 2, 3, 4, 5, 6, 7, 8}) {
		for (int j : {1, 2, 3, 4, 5, 6, 7, 8}) {
			// неиспользуемые не интересуют
			if (color[i][j] == 0)
				continue;

			// если у клетки есть смежная используемая по какой-то из сторон,
			// то он не будет учитываться в периметре
			if (color[i - 1][j] == 1)
				--ans;
			if (color[i + 1][j] == 1)
				--ans;
			if (color[i][j - 1] == 1)
				--ans;
			if (color[i][j + 1] == 1)
				--ans;
		}
	}

	cout << ans;

}

/*
input:
3
1 1
1 2
2 1

output:
8
*/