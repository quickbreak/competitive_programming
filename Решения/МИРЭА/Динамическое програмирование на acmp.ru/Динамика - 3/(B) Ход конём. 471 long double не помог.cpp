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
#include<limits>
#include<iomanip>

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
	
	int n; cin >> n;
	vector<long double> d(n + 1);
	vector<pair<long double, long double>>cnt(10); // first - сколько было, second - сколько стало 
	// база динамики
	d[1] = 10 - 2; // не может начинаться с 0 и 8
	fori(i, 1, 10)
	{
		if (i == 8)
			continue;
		else cnt[i].second = 1;

	}
	// динамика
	fori(i, 2, n + 1) {
		fori(j, 0, 10)
		{
			cnt[j].first = cnt[j].second;
		}
		d[i] = 3 * (cnt[4].first + cnt[6].first);
		fori(j, 0, 10)
		{
			if (j != 4 && j != 6 && j != 5)
			{
				d[i] += 2 * cnt[j].first;
			}
		}

		cnt[0].second = cnt[4].first + cnt[6].first;
		cnt[1].second = cnt[6].first + cnt[8].first;
		cnt[2].second = cnt[7].first + cnt[9].first;
		cnt[3].second = cnt[4].first + cnt[8].first;
		cnt[4].second = cnt[3].first + cnt[9].first + cnt[0].first;
		cnt[6].second = cnt[0].first + cnt[7].first + cnt[1].first;
		cnt[7].second = cnt[2].first + cnt[6].first;
		cnt[8].second = cnt[1].first + cnt[3].first;
		cnt[9].second = cnt[2].first + cnt[4].first;
	}
	std::cout << std::fixed << std::setprecision(0);
	cout << d[n];

}