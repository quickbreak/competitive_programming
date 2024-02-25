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

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<vector<int>>adj(n);
		int u, v;
		fori(i, 0, n - 1) {
			cin >> v;
			--v;
			adj[i + 1].push_back(v);
			adj[v].push_back(i + 1);
		}
		str s; cin >> s;
		/*
		студенты, которые хотят веселиться и слушать музыку (обозначены P
),		студенты, которые хотят спать и наслаждаться тишиной (обозначены S
), и
		студенты, которым не важно, что делать ночью (обозначены C
).
		*/
		vector<int>used(n);
		int ans = 0;
		function<void(int)>dfs = [&](int u) {
			//assert(used[u] == 1);

			used[u] = 1;
			bool Pexists = false;
			bool flag = false;
			for (int v : adj[u])
			{
				if (s[v] == 'P')
					Pexists = true;
				else if (used[v] == 0)// && s[v] != 'P'
				{
					dfs(v);
					//flag = true;
				}
			}
			/*if (!flag && cnt == 1 || cnt == 2)
				++ans;*/
			//ans += cnt;

			};

		fori(i, 0, n) {
			if (used[i] == 0 && s[i]=='S')
				dfs(i);
		}
		cout << ans; cn;
	}

}