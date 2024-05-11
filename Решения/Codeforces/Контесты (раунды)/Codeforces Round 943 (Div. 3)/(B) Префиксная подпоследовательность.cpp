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

	int t, n; cin >> t;
	while (--t >= 0) {
		int m;
		cin >> n >> m;
		str a, b;
		cin >> a >> b;
		int l = 0, r = n + 1, k;
		while (r - l > 1) {
			k = (r + l) / 2; // сколько

			int cnt = 0;
			int uka = 0, ukb = 0;
			while (ukb < m && uka < k) {
				while (b[ukb] != a[uka]) {
					++cnt;
					if (ukb + 1 < m)
						++ukb;
					else break;
				}
				if (ukb < m && (b[ukb] == a[uka])) {
					++uka;
					++ukb;
				}
				else
					break;
			}
			if (uka == k) {
				l = k;
			}
			else r = k;
		}
		cout << l << '\n';
	}
}
