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
		int k;
		cin >> n >> k;
		vector<int>res;
		int missing = 0;
		// найдём степень двойки, которую должны выкинуть
		while ((1 << (missing + 1)) <= k) {
			++missing;
		}
		// k + 1 для заполнения чисел [k + 1 ... k + 1 + 2^missing - 1]
		res.push_back(k + 1);
		// собственно, k + 1 + 2^missing
		res.push_back(k + 1 + (1 << missing));

		// k - 2^missing для заполнения чисел [2^missing ... 2^missing + 2^missing-1 ]
		res.push_back(k - (1 << missing)); // если k - это степень двойки, 
		// то есть k == 2^missing, добавится просто 0
	
		int power = 0;
		// не забываем закинуть все степени двойки кроме missing
		while ((1 << power) < n) {
			if (power != missing)
				res.push_back((1 << power));
			++power;
		}
		cout << res.size() << '\n';
		for (int& x : res)
			cout << x << ' ';
		cout << '\n';
	}
}

/*
Даны два целых числа n и k
Найдите последовательность a неотрицательных целых чисел размером не более 25, 
такую, что выполняются следующие условия:
1) Нет подпоследовательности a с суммой k
2) Для всех 1<=v<=n, где v!=k, существует подпоследовательность a с суммой v
*/