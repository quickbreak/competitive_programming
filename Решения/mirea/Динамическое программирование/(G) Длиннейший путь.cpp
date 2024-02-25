#include<iostream>
#include<cstdio>
#include<cmath>
#include<set>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<any>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<cassert>

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


	int n, m; cin >> n >> m;
	++n;
	int u, v;
	vector<vi>a(n);
	fori(i, 0, m) {
		cin >> u >> v;
		a[u].push_back(v);

	}
	vi used(n);
	queue<int>q;
	vi cnt(n);
	int ans = 0;
	fori(i, 1, n) {
		if (!used[i]) {
			q.push(i);
			cnt[i] = 0;
			while (!q.empty()) {
				u = q.front();
				used[u] = 1;
				q.pop();
				fori(j, 0, a[u].size()) {
					if (cnt[u] + 1 > cnt[a[u][j]]) {
						q.push(a[u][j]);
						cnt[a[u][j]] = cnt[u] + 1;
						ans = max(ans, cnt[a[u][j]]);
					}

				}

			}

		}

	}
	cout << ans;
}