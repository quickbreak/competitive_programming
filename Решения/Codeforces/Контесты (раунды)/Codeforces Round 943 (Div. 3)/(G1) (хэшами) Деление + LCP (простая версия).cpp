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

int nod(int a, int b) {
	if (b == 0)
		return a;
	return nod(a, a % b);
}


int32_t main()
{
	useless;

	int t, n; cin >> t;
	while (--t >= 0) {
		int k;
		cin >> n >> k >> k;

		string s;  int i1, i2, len; // входные данные

		cin >> s;

		// считаем все степени p
		const int p = 31;
		vector<long long> p_pow(s.length());
		p_pow[0] = 1;
		for (size_t i = 1; i < p_pow.size(); ++i)
			p_pow[i] = p_pow[i - 1] * p;

		// считаем хэши от всех префиксов
		vector<long long> h(s.length());
		for (size_t i = 0; i < s.length(); ++i)
		{
			h[i] = (s[i] - 'a' + 1) * p_pow[i];
			if (i)  h[i] += h[i - 1];
		}

		int l = 0, r = n + 1;
		long long h1, h2;
		int cnt = 0;
		while (r - l > 1) {
			len = (r + l) / 2;
			cnt = 1;
			i1 = 0;
			h1 = h[i1 + len - 1];
			if (i1)  h1 -= h[i1 - 1];
			int ukl = 0 + len, ukr = len;
			while (ukl + len - 1 < n) {
				i2 = ukl;
				h2 = h[i2 + len - 1];
				if (i2)  h2 -= h[i2 - 1];

				if (i1 < i2 && h1 * p_pow[i2 - i1] == h2 ||
					i1 > i2 && h1 == h2 * p_pow[i1 - i2]) {

					++cnt;
					ukl = ukl + len;
				}
				else
					++ukl;
			}
			if (cnt >= k)
				l = len;
			else
				r = len;
		}
		cout << l << '\n';
		//// получаем хэши двух подстрок
		//long long h1 = h[i1 + len - 1];
		//if (i1)  h1 -= h[i1 - 1];
		//long long h2 = h[i2 + len - 1];
		//if (i2)  h2 -= h[i2 - 1];

		//// сравниваем их
		//if (i1 < i2 && h1 * p_pow[i2 - i1] == h2 ||
		//	i1 > i2 && h1 == h2 * p_pow[i1 - i2])
		//	cout << "equal";
		//else
		//	cout << "different";
	}
}
