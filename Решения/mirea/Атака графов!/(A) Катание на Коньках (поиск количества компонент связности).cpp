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
	vector<pair<int, int>>v(n);
	fori(i, 0, n)
	{
		cin >> v[i].first >> v[i].second;
	}
	vector<vector<int>>adj(n);
	fori(i, 0, n)
	{
		fori(j, 0, n)
		{
			if (i == j)
			{
				continue;
			}
			if (v[j].first == v[i].first || v[j].second == v[i].second)
				adj[i].push_back(j);
		}
	}

	queue<int>q;
	vector<int>used(n);
	int adjacency_components_count = 0;
	fori(i, 0, n) {
		if (used[i] == 1)
			continue;

		++adjacency_components_count;
		q.push(i);
		while (q.size() > 0) {
			int u = q.front();
			q.pop();
			if (used[u] == 1)
			{
				continue;
			}
			used[u] = 1;
			for (int v : adj[u]) {
				if (!used[v])
					q.push(v);
			}

		}
	}

	cout << adjacency_components_count - 1;

}