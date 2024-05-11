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

	int n; cin >> n;
	vi cost(n);
	fori(i, 0, n)
	{
		cin >> cost[i];
	}
	vector<vector<int>>adj(n);
	vector<vector<int>>radj(n); // reversed order of edges
	int m; cin >> m;
	int u, v;
	while (--m >= 0) {
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		radj[v].push_back(u);

	}

	vi used(n);
	vector<pair<int, int>>timeout(n);
	int ttime = 0;
	// видимо, не обязательно связный
	function<void(int)>dfs = [&](int(u)) {
		used[u] = 1;
		for (int v : adj[u])
		{
			if (!used[v])
				dfs(v);
		}
		timeout[u] = { ++ttime, u };
		};

	fori(i, 0, n) {
		if (!used[i])
			dfs(i);
	}

	sort(timeout.rbegin(), timeout.rend()); // сортируем в порядке обхода
	// sort(all(timeout), greater<>());
	// sort(all(timeout)), reverse(all(timeout));

	fori(i, 0, n)
		used[i] = 0;

	queue<int>q;
	int mini = (int)1e9 + 1, cnti = 0;
	ll p = 1, mod = (int)1e9 + 7, summ = 0;
	fori(i, 0, n)
	{
		if (!used[timeout[i].second]) { // берём самую корневую из возможных
			mini = (int)1e9 + 1, cnti = 0;
			q.push(timeout[i].second);
			while (q.size()) {
				u = q.front();
				q.pop();
				if (used[u])
					continue;
				used[u] = 1;
				for (int v : radj[u]) // поскольку мы развернули рёбра, 
					// то, запускаясь от одной вершины, мы обойдём
					// только компоненту сильной связности 
					// (для любых двух вершин: из u можно дойти в v
					// и из v можно дойти в u), к которой принадлежит
					// эта одна вершина
					if (!used[v])
						q.push(v);
				if (cost[u] < mini) {
					mini = cost[u];
					cnti = 1;
				}
				else if (cost[u] == mini)
					++cnti;
			}

			summ += mini;
			p = p * cnti % mod;
		}
	}
	cout << summ << ' ' << p;
	
}