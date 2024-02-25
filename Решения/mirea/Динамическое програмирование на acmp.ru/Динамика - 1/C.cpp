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
	
	int n; cin >> n;
	vector<pair<int, int>>a(n); // a[i] - {возраст, риск раскрытия агента i}
	fori(i, 0, n)
		cin >> a[i].first >> a[i].second;
	sort(all(a));
	reverse(all(a)); // от старшего к младшему

	// для первых двух агентов 
	// риск раскрытия всегда равен риску раскрытия старшего
	ll ans = a[0].second;
	if (n >= 3)
		ans += a[n - 2].second; // для последних двух агентов так же
	int uk = 2;
	while (uk <= n - 3) {
		ans += min(a[uk - 1].second, a[uk].second); // для каждого агента:
		// либо ставим его в пару к старшему агенту
		if (a[uk - 1].second < a[uk].second) {
			uk += 1;
		}
		else uk += 2; // либо ему в пару ставим младшего

	}
	cout << ans;

}

/*
7
100 2 99 1 98 5 97 1 96 3 95 1 94 2
-- 5

7
100 2 99 2 98 2 97 2 96 2 95 2 94 2
*/