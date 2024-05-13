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

/*
log base(number),
returns power such as base^power <= number
and answer if the number is the base in the power
*/
pair<int, bool> log(int base, int number) {
	if (base == 2) {
		int power = 0;
		while ((1 << power) < number)
			++power;
		return make_pair(power, (1 << power) == number);
	}
	int power = 0, baseinpower = 1;
	while (baseinpower < number) {
		++power;
		baseinpower *= base;
	}
	return make_pair(power, baseinpower == number);
}


int32_t main()
{
	useless;
	
	int n, time; cin >> n >> time;
	vector<pair<int, int>>a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first >> a[i].second;
	}

	int l = -1, r = n + 1, m;
	while (r - l > 1) {
		int m = (r + l) / 2; // количество друзей
		if (m == 0)
		{
			l = m;
			continue;
		}
		multiset<int>times;
		long long summa = 0;
		for (int i = 0; i < m; ++i) {
			times.insert(a[i].second);
			summa += a[i].second;
		}
		if (summa + a[m - 1].first <= time) {
			l = m;
			continue;
		}

		for (int i = m; i < n; ++i) { // берём m самых быстрых из левых (на координатной прямой) i друзей
			times.insert(a[i].second);
			summa += a[i].second;
			auto it = prev(times.end());
			summa -= *it;
			times.erase(it);

			if (summa + a[i].first <= time) {
				l = m;
				break;
			}
		}
		if (l != m)
			r = m;
	}
	cout << l;
}