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

int nod(int a, int b) {
	if (b == 0)
		return a;
	return nod(a, a % b);
}


int32_t main()
{
	useless;

	int t, n; cin >> t;
	while (--t >= 0) {
		int k;
		cin >> n >> k;
		int posb, poss; cin >> posb >> poss; // начальные позиции
		vector<long long>p(n + 1), a(n + 1); 
		for (int i = 1; i <= n; ++i)
			cin >> p[i];
		for (int i = 1; i <= n; ++i)
			cin >> a[i];

		long long bb = 0LL, bs = 0LL; // балансы парней
		ll maxb = 0LL, maxs = 0LL; // максимально возможная сумма (при оптимальной игре)
		int cnt = k;
		// k <= 1e9
		// но нет смысла проверять все k ходов
		// потому что вариантов, куда пойти и где остаться (это одна и та же позиция), всего n
		while ((cnt > 0) && (k - cnt <= n)) { // Bodya
			bb += a[posb];
			--cnt;
			maxb = max(maxb, bb + a[posb] * cnt); // возможно, остаться на этом месте - оптимальный вариант
			posb = p[posb]; // но мы проверим все варианты
		}
		cnt = k;
		while ((cnt > 0) && (k - cnt <= n)) { // Sasha
			bs += a[poss];
			--cnt;
			maxs = max(maxs, bs + a[poss] * cnt); // возможно, остаться на этом месте - оптимальный вариант 
			poss = p[poss]; // но мы проверим все варианты
		}

		if (maxb > maxs)
			cout << "Bodya\n";
		else if (maxs > maxb)
			cout << "Sasha\n";
		else
			cout << "Draw\n";
	}
}
