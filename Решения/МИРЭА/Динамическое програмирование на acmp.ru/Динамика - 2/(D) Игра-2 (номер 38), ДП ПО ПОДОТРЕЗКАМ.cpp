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
	vi a(n);
	fori(i, 0, n)
		cin >> a[i];
	// ИДЕЯ: 1) ДАВАЙТЕ БУДЕМ МАКСИМИЗИРОВАТЬ НЕ ЧЬЮ-ТО ПОБЕДУ
	// А ЧЬЮ-ТО (ПЕРВЫЙ МИНУС ВТОРОЙ) РАЗНОСТЬ ОЧКОВ С ДРУГИМ ИГРОКОМ
	// 2) ЗАМЕТИМ, ЧТО ТАКАЯ ФУНКЦИЯ - ЭТО КАКАЯ-ТО ЗНАКОПЕРЕМЕННАЯ СУММА
	// ГДЕ С ПЛЮСОМ ВЗЯТЫ ЧИСЛА ПЕРВОГО, С МИНУСОМ - ВТОРОГО
	// НАПРИМЕР, a[1]-a[4]+a[3]-a[2]
	// a[1]-a[4]+a[3]-a[2] = a[1] - (a[4]-a[3]+a[2])
	// а что же это такое в скобке?
	// а это та максимальная функция разности, которую может получить игрок, 
	// который на том [2, 4] отрезке ходит первым, то есть оппонент первого ходящего на [1, 4]
	// а по условию он тоже играет оптимально, так что получится именно такая функция.
	// a[1] - (a[4]-a[3]+a[2]) = a[1] - dp[2][4]
	// выходит, на отрезке [i, j] у игрока 2 варианта (берём же только с одного из краёв): 
	// a[i] - dp[i+1][j] и a[j] - dp[i][j-1]

	// dp[i][j] - максимальная разность баллов, набранных первым и вторым,
	// лучший вариант для оказавшегося перед этим отрезком игрока
	vector dp(n, vector(n, 0));
	// отрезок длины 1
	fori(i, 0, n)
		dp[i][i] = a[i];
	// когда перед нами отрезок длины len, для ответа на нём нам надо обратиться
	// к двум отрезкам длины len - 1
	// поэтому будет считать в порядке возрастания длины отрезка
	for (int len = 2; len <= n; ++len) {
		// двигаем два указателя с фиксированным расстоянием между ними, 
		// считаем ответ для каждого отрезка длины len
		for (int i = 0, j = len - 1; j < n; ++i, ++j) {
			dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
		}
	}
	cout << (dp[0][n - 1] > 0 ? 1 : dp[0][n - 1] < 0 ? 2 : 0);

}

/*
5
1 10000000 1 1 1
--2

*/