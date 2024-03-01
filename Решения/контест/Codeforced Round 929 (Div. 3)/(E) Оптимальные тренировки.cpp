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
	
	int t, n; cin >> t;
	while (--t >= 0) {
		cin >> n;
		vl pref(n + 1); // pref[i] - сколько участков на отрезке [0, i]
		int x;
		fori(i, 0, n)
		{
			cin >> x;
			pref[i + 1] = pref[i] + x;

		}
		int q; cin >> q;
		int l, u;
		vi res;
		while (--q >= 0) {
			cin >> l >> u;
			// u + pref[l - 1] - количество участков, за прохождение которых мы получаем 
			// положительное число баллов
			// так что ищем ближайшее к этому число
			// и проверяем его и его предыдущего соседа: какой даст меньше минуса (больше плюса)
			int uk = int(lower_bound(all(pref), u + pref[l - 1]) - pref.begin());
			
			int ans = -1;
			ll variant_1 = -ll(1e18), variant_2 = -ll(1e18), variant_3 = -ll(1e18), k;
			if (uk < l) {
				ans = l;
			}
			else {
				if (uk <= n) {
					k = pref[uk] - pref[l - 1]; // количество участков с l до uk района
					variant_1 = (u + u - (k - 1)) * k / 2; // сумма баллов за все участки с l до uk маршрута

				}
				if (uk - 1 >= l) {
					k = pref[uk - 1] - pref[l - 1];
					variant_2 = (u + u - (k - 1)) * k / 2;
				}
				if (variant_2 >= variant_1) // ищем наименьшую правую границу, поэтому >=
					ans = uk - 1;
				else ans = uk;
			}
			res.push_back(ans);
			
		}
		for (int x : res)
			cout << x << ' ';
		cout << '\n';
	}

}
/*
1
6
3 1 4 1 5 9
3
1 8
2 7
5 9

1
5
7 9 2 5 2
10
1 37
2 9
3 33
4 32
4 15
2 2
4 2
2 19
3 7
2 7

*/