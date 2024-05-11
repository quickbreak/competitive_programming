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

	/*
	Вася решил питаться рыбой. Он решил, что в течение N дней он должен съедать по одной рыбе каждый день. 
	К сожалению, рыба — товар скоропортящийся и может храниться не более K дней, включая день покупки. 
	С помощью методов машинного обучения Вася предсказал цены на рыбу на N дней вперёд.
	Помогите Васе определить, в какие дни и сколько рыбы нужно покупать, чтобы потратить как можно меньше денег.
	*/
	// сортим по стоимости, и идём от меньшей к большей
	// если смог купить рыбу на i день по меньшей стоимости, нет надобности тратить больше
	// каждая стоимость покрывает отрезок k вперёд
	// 
	// 1 - на этот день рыба куплена
	// 0 - нет
	// ищу l = первый 0 за i
	// ищу r = первую 1 за l
	// r = min(r, i+k)
	// i..r - единицы
	// и удалить их из нулей надо

	int n, k; cin >> n >> k;
	set<int>nol, odin;
	for (int i = 0; i < n; ++i)
		nol.insert(i);
	vector<pair<int, int>>a;
	int x;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		a.push_back(make_pair(x, i));
	}
	sort(all(a));

	long long ans = 0; // сколько денег потрачено всего
	long long cost;
	int day, l, r;
	vector<int>res(n); // res[i] == сколько рыбы купить в день i
	for (int i = 0; i < n; ++i) {
		cost = a[i].first;
		day = a[i].second;
		// первый 0 за day. Точка старта
		auto it = nol.lower_bound(day);
		if (it != nol.end())
			l = *(it);
		else
			l =  n;
		// первая 1 за 0(l). Точка конца (не включительно, надо -1)
		it = odin.lower_bound(l);
		if (it != odin.end())
			r = *(it)-1;
		else r = n - 1;
		r = min(r, day + k - 1);
		// покупаю рыбу на дни [l..r]
		for (int j = l; j <= r; ++j) {
			nol.erase(j);
			odin.insert(j);
			ans += cost;
		}

	
		res[day] = max(r - l + 1, 0);
		if (odin.size() == n)
			break;
	}
	cout << ans << '\n';
	for (int i = 0; i < n; ++i)
		cout << res[i] << ' ';

}

/*
2 1
1 2
--3
--1 1


3 2
3 1 2
--5
--1 2 0
*/