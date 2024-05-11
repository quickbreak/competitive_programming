#include<algorithm>
#include<any>
#include<cassert>
#include<cmath>
#include<cstdio>
#include<deque>
#include<functional>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<vector>

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
using vl = vector<ll>;
using vvi = vector<vector<int>>;

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
	
	int n, q; cin >> n >> q;
	int u, v, w;
	vector<vector<pair<int, int>>>adj(n); // a[u][i] = w, v
	vector<pair<int, pair<int, int>>>edge;
	fori(i, 0, q)
	{
		cin >> u >> v >> w;
		--u, --v;
		adj[u].push_back({ w, v });
		adj[v].push_back({ w, u });
		edge.push_back({ w, {u, v} });

	}
	sort(all(edge));
	int l = -1, r = edge.size(), m;
	/*
	0 - not visited
	1 - first part
	2 - second part
	*/
	vi color(n);
	bool flag;
	function<void(int)>dfs = [&](int(u)) { // проверка графа на двудольность

		for (auto v : adj[u])
		{
			if (v.first < edge[m].first)
			{
				if (color[v.second] == 0)
				{
					color[v.second] = 1 + 2 - color[u];
					dfs(v.second);
				}
				else if (color[v.second] == color[u])
				{
					flag = true;
					return;
				}

			}
		}


		};

	while (r - l > 1) {
		m = (r + l) / 2;
		flag = false; // нашли ребро меньше edge[m],
		// которое соединяет вершины разных долей?
		fori(i, 0, n)
			color[i] = 0;
		fori(i, 0, n)
			if (color[i] == 0) {
				color[i] = 1;
				dfs(i);
			}

		if (flag) // не получилось
		{
			r = m;
			/*
			Граф не двудольный, значит, в нём есть циклы нечётной длины.
			Если мы уменьшим max ребро, уменьшится количество рёбер,
			и, возможно, уйдут и эти циклы нечётной длины
			*/
		}
		else l = m;
	}

	cout << edge[l].first;

}