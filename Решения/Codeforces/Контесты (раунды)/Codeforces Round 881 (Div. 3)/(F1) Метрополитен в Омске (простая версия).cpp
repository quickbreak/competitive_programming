#include <iostream>
#include <vector>
#include <set>
#include <map>


using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n; cin >> t;
	while (--t >= 0) {
		cin >> n;
		vector<int>maxpath(2), minpath(2), maxsuff(2), minsuff(2);
		maxpath[1] = minpath[1] = maxsuff[1] = minsuff[1] = 1;
		char command;
		int u, v, x;
		while (--n >= 0) {
			cin >> command;
			if (command == '+') {
				cin >> v >> x;
				// пересчитываем максимальные и минимальные стоимости пути из 1 в v
				maxsuff.push_back(max(x, maxsuff[v] + x));
				minsuff.push_back(min(x, minsuff[v] + x));
				maxpath.push_back(max(maxpath[v], maxsuff[maxsuff.size() - 1]));
				minpath.push_back(min(minpath[v], minsuff[minsuff.size() - 1]));
			}
			else {
				// поскольку вес каждой вершины - это либо 1, либо -1:
				// на пути из u в v встречаются подотрезки всех стоимостей
				// от минимальной стоимости на пути из u в v до максимальной
				cin >> u >> v >> x;
				if (x == 0)
					cout << "YES\n";
				else
					cout << ((x >= minpath[v] && x <= maxpath[v]) ? "YES\n" : "NO\n");
			}
		}
	}
}
