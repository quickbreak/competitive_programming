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
	// ЗАМЕТИМ, ЧТО
	// если есть хотя бы одно число, которое повторяется на k картах
	// то мы можем бесконечно его заменять на k - 1 карту другого числа
	// тем самым удаляя числа одно за другим
	// в конце останется k - 1 карта какого-то числа.
	// Если каждое число встречается меньше k раз, ни одной операции сделать невозможно
	int t, n; cin >> t;
	while (--t >= 0) {
		int k;
		cin >> n >> k;
		int x;
		map<int, int>mp; // mp[x][cnt] - сколько раз встречается число х
		int cntk = 0; // флаг: есть ли число, встречающееся >= k раз
		for (int i = 0; i < n; ++i) {
			cin >> x;
			mp[x]++;
			if (mp[x] >= k) {
				++cntk;
			}
		}

		if (cntk > 0)
			cout << k - 1 << '\n';
		else cout << n << '\n';
	}
}

/* 
5 3
4 1 1 4 4
--YES
У вас есть n карт, на каждой карте написано число, а также фиксированное целое число k. 
Вы можете выполнять следующую операцию любое количество раз:
	Выберите любые k карт, на которых написано одно и то же число. 
	Обменяйте эти карты на k - 1 карт, каждая из которых может иметь любое число, 
	которое вы выберете (включая число, написанное на меняемых вами картах).

Какое минимальное количество карт у вас может остаться в конце этого процесса?
 */