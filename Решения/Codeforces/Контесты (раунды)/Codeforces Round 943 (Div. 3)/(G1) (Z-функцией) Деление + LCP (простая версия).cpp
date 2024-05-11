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


vector<int> z_function(string s) {
	int n = (int)s.size();
	vector<int>z(n, 0);
	int l = 0, r = 0;
	for (int i = 1; i < n; ++i) {
		// если мы уже видели этот символ
		if (i <= r)
			// то мы можем попробовать его инициализировать z[i - l],
			// но не дальше правой границы: там мы уже ничего не знаем
			z[i] = min(r - i + 1, z[i - l]);
		// дальше каждое успешное увеличение z[i] сдвинет z-блок на единицу
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			z[i]++;
		// проверим, правее ли мы текущего z-блока
		if (i + z[i] - 1 > r) {
			r = i + z[i] - 1;
			l = i;
		}
	}
	return z;
}


int32_t main()
{
	useless;

	int t, n; cin >> t;
	while (--t >= 0) {
		int k;
		cin >> n >> k >> k;
		str s; cin >> s;

		auto z = z_function(s);

		int l = 0, r = n + 1, len;
		while (r - l > 1) { // бинарим длину
			len = (r + l) / 2;

			int uk = len, cnt = 1;
			// идём по строке и делим её на 
			// максимальное количество частей длины >= len
			// то есть на каждой итерации находим ближайшее z[j] >= len
			while (uk < z.size()) {
				while (uk < z.size() && z[uk] < len)
					++uk;
				if (uk < z.size()) { // если удалось взять ещё одну подстроку
					uk = uk + min(z[uk], len); // возьмём от неё минимальную часть (для максимизации количества)
					++cnt;
				}
			}
			if (cnt >= k)
				l = len;
			else
				r = len;
		}
		cout << l << '\n';
	}
}
