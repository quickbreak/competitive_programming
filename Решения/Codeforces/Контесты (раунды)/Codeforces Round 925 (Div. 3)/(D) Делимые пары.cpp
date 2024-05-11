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

	int t; cin >> t;
	int n, x, y;
	while (t--) {
		cin >> n >> x >> y;
		vector<int>a(n);
		fori(i, 0, n)
			cin >> a[i];

		map<pair<int, int>, int>mp;
		fori(i, 0, n)
		{
			++mp[make_pair(a[i] % x, a[i] % y)];
		}
		int ox, oy, res;
		ll ans = 0;
		fori(i, 0, n)
		{
			ox = a[i] % x;
			oy = a[i] % y;
			res = mp[make_pair((x - ox) % x, oy)];
			if (((ox == x / 2) && (x%2==0)) || (ox == 0)) //(ox == ((x - ox) % x))
				--res;
			ans += max(res, 0);
			
		}
		cout << ans / 2; cn;

	}

}