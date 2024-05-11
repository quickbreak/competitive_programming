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
	// если есть клетки одинакого цвета на левой, правой, верхней и нижней полосках,
	// то всегда можно, проведя прямоугольники через каждую пару, закрасить всё поле в этот цвет
	int t, n; cin >> t;
	while (--t >= 0) {
		int m;
		cin >> n >> m;
		vector<vector<char>>a(n, vector<char>(m));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> a[i][j];
			}
		}
		vector<int>black(4), white(4);
		for (int j = 0; j < m; ++j) {
			if (a[0][j] == 'W') // верхняя полоска
				white[0]++;
			if (a[0][j] == 'B')
				black[0]++;
			if (a[n - 1][j] == 'W') // нижняя полоска
				white[1]++;
			if (a[n - 1][j] == 'B')
				black[1]++;
		}
		for (int j = 0; j < n; ++j) {
			if (a[j][0] == 'W') // левая полоска
				white[2]++;
			if (a[j][0] == 'B')
				black[2]++;
			if (a[j][m - 1] == 'W') // правая полоска
				white[3]++;
			if (a[j][m - 1] == 'B')
				black[3]++;
		}
		if (black[0] && black[1] && black[2] && black[3] || white[0] && white[1] && white[2] && white[3])
			cout << "YES\n";
		else cout << "NO\n";
	}
}

/*
6 6
WWWWBW
WBWWWW
BBBWWW
BWWWBB
WWBWBB
BBBWBW
--YES

Дана таблица n*m из белых и черных клеток. 
За одну операцию можно выбрать две клетки одного цвета 
и покрасить в этот цвет все клетки в подпрямоугольнике между ними.

Возможно ли, чтобы все клетки в таблице были одного цвета после выполнения любого количества операций (возможно, нуля)?
 */