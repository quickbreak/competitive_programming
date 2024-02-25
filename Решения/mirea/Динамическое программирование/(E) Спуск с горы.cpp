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

	//freopen("slalom.in.in", "rt", stdin);
	//freopen("slalom.in.out", "wt", stdout);

	int n; cin >> n;
	vector<vector<ll>> a(n, vector<ll>(n + 1, -1e18));
	fori(i, 0, n)
	{
		fori(j, 1, n + 1)
		{
			if (j <= i + 1)
				cin >> a[i][j];
		}
	}

	vector<vector<ll>> d(n, vector<ll>(n + 1, -1e18));
	d[0][1] = a[0][1];
	fori(i, 1, n)
	{
		fori(j, 1, i + 2)
		{
			d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + a[i][j];
		}
	}

	/*fori(i, 0, n)
	{
		fori(j, 1, n + 1)
		{
			if (j <= i + 1)
				cout << d[i][j] << ' ';
		}
		cn;
	}*/

	ll ans = -1e18;
	fori(j, 1, n + 1)
	{
		ans = max(ans, d[n - 1][j]);
	}
	cout << ans;
}