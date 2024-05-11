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
#include<random>
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
using vvl = vector<vector<long long>>;

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

	ll t, n; cin >> t;
	while (--t >= 0) {
		ll k;
		cin >> n >> k;
		vector<long long>a(n);
		ll minel = 10000000000000;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			minel = min(minel, a[i]);
		}
		ll ans = ((minel > 0) ? ((minel - 1) * (1LL * n) + 1) : 0);
		for (int i = 0; i < n; ++i) {
			a[i] -= minel;
		}
		sort(all(a));
		vector<ll>prefsum(n + 1);
		fori(i, 0, n)
			prefsum[i + 1] = prefsum[i] + a[i];

		ll l = -1, r = n, m = 0;
		while (r - l > 1) {
			m = (r + l) / 2;
			if (k >= a[m] * (m)-(prefsum[m])) { //?  проверил
				l = m;
			}
			else
				r = m;
		}
		// а если изначально ноль, то откуда связи со страмыи??!			сделал
		if (l > -1) {
			if (a[l] > 0) {
				ans += ((ans > 0) ? n - 1 : 0) + (a[l] - 1) * (1LL * n) + 1;
				k -= a[l] * (l)-(prefsum[l]);
			}

			ll cnt = k / (l + 1);
			k = k % (l + 1);
			ans += n - 1 + (cnt - 1) * (1LL * n) + 1;
		}
		/*else if (l > -1 && a[l] == 0) {
			ll cnt = k / (l + 1);
			k = k % (l + 1);
			ans += min(n - 1, (cnt - 1) * (1LL * n) + 1) + (cnt - 1) * (1LL * n) + 1;
		}*/
		ans += k;
		ans += n - l - 1;
		// а если k больше даже a[n-1]?
		cout << ans << '\n';
	}
}

/*
1
3 20
0 1 2
--4
*/
