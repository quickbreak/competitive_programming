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
	
	int n; cin >> n;
	vi	even_cnt(n + 1), a(n); // количество чётных элементов
	int x, pos;
	fori(i, 0, n)
	{
		cin >> a[i];
		x = a[i];
		even_cnt[i + 1] = even_cnt[i];
		if (abs(x) % 2 == 0)
			++even_cnt[i + 1];
	}
	fori(i, 0, n)
	{
		x = a[i];
		if (abs(x) % 2 != 0) // нашли первое нечётное число
		{
			if (even_cnt[i] < even_cnt[n]) // если после него есть чётные
			{
				pos = i; // берём его
				break;
			}
			else {
				pos = n - 1; // иначе возьмём последнее (раз они дальше все нечётные)
				break;
			}
		}
	}

	if (even_cnt[n] > 0) { // если есть чётные
		fori(i, 0, pos - 1) {
			cout << char(120); // то к чётному произведению
		}
		if (pos > 0) // если нечётное число не в начале ряда
			cout << char(43); // прибавим нечётное число
		if (pos < n - 1) // если нечётное число не в конце ряда
			cout << char(43); // к нему прибавляем дальше
		fori(i, pos + 1, n - 1)
			cout << char(120); //чётное произведение

	}
	else {
		fori(i, 1, n)
			cout << char(120);
	}
}
/*
3
2 5 2

3 
5 7 2

2
4 -5
*/