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


bool flag = false;


void dfs_find_cycle(int u, vector<int>& used, vector<vector<int>>& a) {
	used[u] = 1;

	fori(i, 0, a[u].size()) {
		if (used[a[u][i]] == 0)
			dfs_find_cycle(a[u][i], used, a);
		else if (used[a[u][i]] == 2)
			continue;
		else if (used[a[u][i]] == 1)
		{
			flag = true;
			return;
		}
	}

	used[u] = 2;
}



int main()
{
	useless;

	int t; cin >> t;
	int n, k;
	while (t--) {
		flag = false;
		cin >> n >> k;

		vector<vector<int>>v(k, vector<int>(n));
		fori(i, 0, k) {
			fori(j, 0, n)
				cin >> v[i][j];
		}
		if (k == 1)
		{
			cout << "YES\n";
			continue;
		}


		vector<vector<int>>a(n + 1);
		fori(i, 0, k) {
			fori(j, 2, n)
			{
				a[v[i][j - 1]].push_back(v[i][j]);
			}
		}


		vector<int>used(n + 1);
		fori(i, 1, n + 1)
		{
			if (used[i] == 0)
			{
				dfs_find_cycle(i, used, a);
				if (flag)
					break;
			}
		}
		if (flag)
			cout << "NO\n";
		else cout << "YES\n";
	}

}