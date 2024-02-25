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

	int t; cin >> t;
	ll a, b;
	while (t--) {
		cin >> a >> b;
		ll p = a * b;
		/*if (p <= (int)1e9)
		{
			cout << p; cn;
			continue;
		}*/
		ll l = 1, r = 1e9 + 1, x;
		int cnt = 0;
		while (r - l > 1) {
			cnt = 0;
			x = (r + l) / 2;
			forl(i, 2, i * i < x) {
				if (x % i == 0) {
					if (cnt == 0) {
						if (x / i == b)
							++cnt;
						else break;
					}
					else if (cnt == 1) {
						if (x / i == a)
							++cnt;
						break;
					}
				}
			}
			if (cnt == 2) {
				r = x;
			}
			else l = x;
		}
		cout << b * r;
		cn;
	}

}