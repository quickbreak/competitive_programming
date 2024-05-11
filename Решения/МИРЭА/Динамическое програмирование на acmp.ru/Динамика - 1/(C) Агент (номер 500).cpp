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
	// напарники - 2 агента с соседними возрастами
	// каждый агент должен иметь хотя бы одного напарника
	// риск пары - риск старшего из пары
	// найти минимальный суммарный риск 
	int n; cin >> n;
	vector<pair<int, int>>a(n + 1); // a[i] - {возраст, риск раскрытия агента i}
	fori(i, 1, n + 1)
		cin >> a[i].first >> a[i].second;
	// сортируем агентов по возрасту
	sort(all(a));
	// dp[i] - минимальный суммарный риск раскрытия при условии, что младшие i агентов соединены
	vector dp(n + 1, int(1e9));
	// первого обязательно присоединить ко второму
	dp[2] = a[2].second;
	// чтобы соединить троих, обязательно соединить всех (1-2, 2-3)
	if (n >= 3)
		dp[3] = dp[3 - 1] + a[3].second;
	for (int i = 4; i <= n; ++i) {
		// 2 варианта:
		// i - 1 агентов соединены, и я добавляюсь к последнему
		// i - 2 агентов соединены, и мы с последним соединяемся
		dp[i] = min(dp[i - 1] + a[i].second, dp[i - 2] + a[i].second);
	}
	cout << dp[n];

}

/*
7
100 2 99 1 98 5 97 1 96 3 95 1 94 2
-- 5

7
100 2 99 2 98 2 97 2 96 2 95 2 94 2
--8
*/