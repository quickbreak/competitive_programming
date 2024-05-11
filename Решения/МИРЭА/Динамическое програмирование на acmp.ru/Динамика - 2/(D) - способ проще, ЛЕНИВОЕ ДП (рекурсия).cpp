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

const int neverget = (int)1e9 + 7;

int32_t main()
{
	useless;
	// игра: берут по очереди число слева или справа
	// у кого больше сумма, тот победил
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
	vector dp(n, vector(n, neverget));
	function<int(int, int)> solve = [&](int l, int r) -> int {
		// иначе до каких пор брать l + 1, r - 1?
		if (l > r)
			return 0;
		// если уже посчитан, не надо считать снова
		// (стопятьсот миллиордов раз будет обращаться к тому, что уже посчитано)
		if (dp[l][r] != neverget)
			return dp[l][r];
		// выбираем число слева либо справа
		int res = max(a[l] - solve(l + 1, r), a[r] - solve(l, r - 1));
		// возврат значения с присвоением (крутяк!)
		return dp[l][r] = res;
	};

	int ans = solve(0, n - 1);
	// победил перый/второй/ничья
	cout << (ans > 0 ? 1 : (ans < 0 ? 2 : 0));

}