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
	// вывести n чисел: число >= 0, чтобы в сумме они давали k, 
	// и в их побитовом ИЛИ было максимальное количество единиц
	// ЗАМЕТИМ, ЧТО:
	// больше всего единиц в числах вида 2^p-1
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		// когда число можно одно, у нас выбора нет
		if (n == 1) {
			cout << k << '\n';
			continue;
		}
		int cnt = 0;
		// когда сумма == 1, основное решение ломается (-50 баллов)
		if (k == 1) {
			cout << 1 << ' ';
			while (++cnt < n)
				cout << 0 << ' ';
			cn;
			continue;
		}
		// основное решение
		int summa = 0;
		int binpower = 1;
		// найдём макс p: 2^p >= k
		while (binpower < k) {
			binpower *= 2;
		}
		// если повезло, и 2^p-1 == k
		if (binpower - 1 == k) {
			cout << binpower - 1 << ' ';
			while (++cnt < n)
				cout << 0 << ' ';
			cn;
			continue;
		}
		// иначе y = 2^(p-1)-1 и добить до суммы
		// больше, чем y, мы уже не прибавим
		// значит мы уже получили максимальное количество единиц
		// добьём до k, и дальше нули
		binpower /= 2;
		cout << binpower - 1 << ' ';
		summa = binpower - 1;
		cout << k - summa << ' ';
		++cnt;
		while (++cnt < n)
			cout << 0 << ' ';
		cn;
		
	}
	

}