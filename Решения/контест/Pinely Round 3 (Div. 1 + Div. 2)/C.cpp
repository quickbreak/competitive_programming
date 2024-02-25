#include<iostream>
#include<cstdio>
#include<cmath>
#include<set>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<any>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<cassert>

#define fori(it, a, b) for(int it = a; it < b; ++it)
#define all(x) (x).begin(),(x).end()
#define cn cout << '\n'
#define minel(v) *min_element(v.begin(), v.end());
#define maxel(v) *max_element(v.begin(), v.end());
#define sortv(v) sort(v.begin(), v.end());
#define forl(a, k, b) for(long long a = k; a < b; ++a)
#define useless ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

using ll = long long;
using str = string;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;

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


int main()
{
	useless;

	//freopen("input.in", "rt", stdin);
	//freopen("output.out", "wt", stdout);

	int n, t; cin >> t;
	ll ans = 0;
	while (t-- > 0) {
		ans = 0;
		cin >> n;
		vector<long long>l(n);
		vector<long long>r(n);
		vector<long long>c(n);
		fori(i, 0, n)
			cin >> l[i];
		sort(all(l));
		fori(i, 0, n)
			cin >> r[i];
		sort(all(r));
		fori(i, 0, n)
			cin >> c[i];
		sort(all(c));
		int curr = -1, pairl = -1, ukl = 0;
		fori(i, 0, n) {
			curr = r[i];
			ukl = lower_bound(l.begin(), l.end(), curr) - l.begin() - 1;
			pairl = l[ukl];
			ans += c[n - i - 1] * (curr - pairl);
		}
		cout << ans; cn;

	}
}