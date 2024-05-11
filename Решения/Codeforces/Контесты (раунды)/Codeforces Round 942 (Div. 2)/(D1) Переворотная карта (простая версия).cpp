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
	else 
		return nod(b, a % b);
}

int32_t main()
{
	useless;
	// ((a + b) % (b * nod(a, b))) == 0 сколько существует пар (а, b)?
	// 
	// почему-то мы решили, что нам подойдут только какие-то из чисел, что делятся на b
	int t, n; cin >> t;
	while (--t >= 0) {
		int m;
		cin >> n >> m;

		ll res = 0LL;
		for (ll b = 1; b <= m; ++b) {
			for (ll a = b; a <= n; a += b) { // только числа, которые делятся на b
				if (((a + b) % (b * nod(a, b))) == 0)
					++res;
			}
		}
		cout << res << '\n';
	}
}
