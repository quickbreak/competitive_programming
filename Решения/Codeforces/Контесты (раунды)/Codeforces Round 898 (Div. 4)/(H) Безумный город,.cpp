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
//define int long long;

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


int32_t main()
{
	useless;
	
	int t; cin >> t;
	while (--t >= 0) {
		int n, a, b; cin >> n >> a >> b;
		int u, v;
		vector<vi>adj(n);
		fori(i, 0, n)
		{
			cin >> u >> v;
			--u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);

		}
		/*
		0 - не посещена
		1 - посещена
		*/
		vi color(n); 
		vi path, res(2, 1e9);
		int meeting = -1;
		function<void(int, int)>dfs1 = [&](int u, int from) {

			color[u] = 1;
			path.push_back(u);
			for (int v : adj[u]) {
				if (color[v] == 0)
					dfs1(v, u);
				else if (color[v] == 1 && v != from && meeting == -1)
				{
					meeting = v;
					int uk = path.size() - 1;
					while (path[uk] != v)
						--uk;
					res[0] = uk + 1;
				}
			}
			path.pop_back();
			};


		function<void(int)>dfs2 = [&](int u) {

			color[u] = 1;
			path.push_back(u);
			for (int v : adj[u]) {
				if (v == meeting) {
					res[1] = min(res[1], ((int)path.size() + 1));
				}
				else if (color[v] == 0)
					dfs2(v);
			}

			path.pop_back();
			};

		dfs1(--b, -1);
		path.clear();
		color.assign(n, 0);
		if (--a == meeting)
			res[1] = 1;
		else dfs2(a);
		assert(res.size() == 2);

		cout << (res[0] < res[1] ? "YES\n" : "NO\n");
	}

}