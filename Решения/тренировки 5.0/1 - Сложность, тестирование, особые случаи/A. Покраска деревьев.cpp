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
	
	int p, v, q, m; cin >> p >> v >> q >> m;
	int ans = 0;
	if (p <= q) {
		int vasya_l = p - v;
		int vasya_r = p + v;
		int masha_l = q - m;
		int masha_r = q + m;
		masha_r = max(masha_r, vasya_r);
		vasya_r = min(vasya_r, masha_l);
		if (vasya_r - vasya_l + 1 > 0)
		{
			ans += vasya_r - vasya_l + 1;
			if (masha_l <= p + v)
				--ans;
		}
		ans += masha_r - masha_l + 1;
	}
	else {
		int masha_l = q - m;
		int masha_r = q + m;
		int vasya_l = p - v;
		int vasya_r = p + v;
		vasya_r = max(vasya_r, masha_r);
		masha_r = min(masha_r, vasya_l);
		if (masha_r - masha_l + 1 > 0) {
			ans += masha_r - masha_l + 1;
			if (vasya_l <= q + m)
				--ans;
		}
		ans += vasya_r - vasya_l + 1;
		
	}
	cout << ans;

}