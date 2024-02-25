#include<algorithm>
#include<any>
#include<cassert>
#include<cmath>
#include<cstdio>
#include<deque>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<functional>

#define fori(it, a, b) for(int it = a; it < b; ++it)
#define all(x) (x).begin(),(x).end()
#define cn cout << '\n'
#define minel(v) *min_element(v.begin(), v.end());
#define maxel(v) *max_element(v.begin(), v.end());
#define sortv(v) sort(v.begin(), v.end());
#define forl(a, k, b) for(long long a = k; a < b; ++a)
#define useless ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

using ll = long long;
using str = string;
using ld = long double;
using vi = vector<int>;
using vvi = vector < vector<int>>;
using vl = vector<ll>;

const ll mod = ll(1e9 + 7);

//base ^ p
ll binpow(ll base, ll p)
{
	if (p == 0)
		return 1;
	if (p == 1)
		return base;
	if (p % 2 == 0)
	{
		ll polovina = binpow(base, p / 2);
		return polovina * polovina % mod;
	}
	else
	{
		ll pminus = binpow(base, (p - 1) / 2);
		ll res = pminus * pminus % mod;
		return res * base % mod;
	}
}


int main()
{
	useless;

	int n, m, k; cin >> n >> m >> k;
	vector<vector<int>>adj(n);
	int u, v;
	while (--m >= 0) {
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);

	}
	// 0 - не посещали
	// 1 - вошли, но не вышли
	// 2 - вышли
	vi color(n);
	vi path; // собираем вершины u, для которых color[u] == 1

	function<void(int, int)>dfs = [&](int u, int p) {
		if (color[u] == 2)
			return;

		color[u] = 1; // вошли в вершину
		path.push_back(u);
		for (int v : adj[u])
		{
			if (v == p) continue; // эта строчка сокращает время в 10 раз: 122 мс против 1300 мс
			// типа без неё мы каждый раз пробегаем по path
			// видимо, мало циклов. Но по-моему, это бредово

			if (color[v] == 1) // нашли цикл?!
			{
				for (int i = path.size() - 1; i >= 0; --i) {
					if (path[i] == v) // нашли начало цикла
						if (path.size() - i >= k + 1)
						{// если длина цикла устраивает, выводим его
							cout << path.size() - i << '\n';
							fori(j, i, path.size()) {
								cout << path[j] + 1 << ' ';
							}
							exit(0);
						}
				}
			}
			else if (color[v] == 0)
				dfs(v, u);
		}

		color[u] = 2; // выжали все соки, больше тут делать нечего
		// если сомневаешься, вспоминай, что граф неориентированный
		path.pop_back();

		};

	fori(i, 0, n) {
		assert(color[i] != 1);
		if (color[i] == 0)
			dfs(i, -1);
	}

}
/* тест к случаю, в котором я сомневался
8 9 5
1 2
2 3
3 4
4 5
5 2
4 6
6 7
7 8
8 2


answer:
6
2 3 4 6 7 8
*/