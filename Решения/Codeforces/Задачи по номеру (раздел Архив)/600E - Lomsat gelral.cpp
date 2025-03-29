#include <iostream>
#include <vector>
#include <map>


using namespace std;


// u - номер вершины
// * я утверждаю, что в корневом дереве у каждой вершины, кроме корня всего дерева, ровно один родитель
void dfs(int u, int parent, const vector<vector<int>>& adj, const vector<int>& colour, vector<map<int, int>>& cnt, vector<int>& max_count, vector<long long>& summa) {
	int max_sz = -1, largest_son = -1;
	for (const int& v : adj[u]) { // сперва нужно посчитать ответ для сыновей
		if (v == parent)
			continue;
		dfs(v, u, adj, colour, cnt, max_count, summa);
		if ((int)cnt[v].size() > max_sz) { // ищем сына вершины u, у которого больше всего различных цветов. Он - large, остальные - small
			max_sz = cnt[v].size();
			largest_son = v;
		}
	}
	if (largest_son == -1) { // вершина u - лист
		cnt[u][colour[u]] = 1;
		max_count[u] = 1;
		summa[u] = colour[u];
		return;
	}
	// у вершины u есть сыновья
	cnt[u] = std::move(cnt[largest_son]); // берём указатель на large, к нему будем сливать small(s)					  <------- STD::MOVE()
	// STD::MOVE() можно заменить на a.swap(b) или swap(a, b), который вызовет a.swap(b), который сделает 3 std::move
	max_count[u] = max_count[largest_son];
	summa[u] = summa[largest_son];
	// добавляем свой цвет, вершины u то есть
	cnt[u][colour[u]]++;
	if (cnt[u][colour[u]] > max_count[u]) {
		max_count[u] = cnt[u][colour[u]];
		summa[u] = colour[u];
	} else if (cnt[u][colour[u]] == max_count[u]) {
		summa[u] += colour[u];
	}
	// сливать к вершине u остальных её сыновей
	for (const int& v : adj[u]) {
		if (v == largest_son || v == parent) {
			continue;
		}
		for (auto& [color, count] : cnt[v]) {
			cnt[u][color] += count;
			if (cnt[u][color] > max_count[u]) {
				max_count[u] = cnt[u][color];
				summa[u] = color;
			} else if (cnt[u][color] == max_count[u]) {
				summa[u] += color;
			}
		}
	}
	return;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	vector<int> colour(n); // colour[i] = цвет вершины i
	for (int& c : colour)
		cin >> c;
	vector<vector<int>> adj(n); // adj[i] = список смежных с i вершин
	for (int i = 0, u, v; i < n - 1; ++i) {
		cin >> u >> v;
		--u;
		--v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<map<int, int>> cnt(n); // cnt[i][color] = сколько раз вершины с цветом color встречаются в поддереве с корнем i
	vector<long long> summa(n); // summa[i] = сумма доминирующих цветов в поддереве с корнем i
	vector<int>max_count(n); // max_count[i] = количество, сигнализирующее о доминировании цвета в поддереве с корнем i
	// корень всего дерева - вершина номер 0
	dfs(0, -52, adj, colour, cnt, max_count, summa);
	for (long long& res : summa) {
		cout << res << ' ';
	}
}
