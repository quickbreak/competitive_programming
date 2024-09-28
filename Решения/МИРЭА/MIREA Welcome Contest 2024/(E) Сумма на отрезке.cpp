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

/*
log base(number),
returns power such as base^power <= number
and answer if the number is the base in the power
*/
pair<int, bool> log(int base, int number) {
	if (base == 2) {
		int power = 0;
		while ((1 << power) < number)
			++power;
		return make_pair(power, (1 << power) == number);
	}
	int power = 0, baseinpower = 1;
	while (baseinpower < number) {
		++power;
		baseinpower *= base;
	}
	return make_pair(power, baseinpower == number);
}

void precalculate(const vector<ll>& a, vector<ll>& pref, vector<ll>& pref_ladder, vector<ll>& suff, vector<ll>& suff_ladder) {
	int n = a.size();
	for (int i = 0; i < n; ++i) {
		pref[i + 1] = pref[i] + a[i];
		pref_ladder[i + 1] = pref_ladder[i] + (i + 1) * a[i];
	}
	for (int i = n - 1; i >= 0; --i) { // >= 0 
		suff[i] = suff[i + 1] + a[i];
		suff_ladder[i] = suff_ladder[i + 1] + (n - i) * a[i];
	}
}

// [L, R] -> get_prefix(L-1, R);
ll get_prefix(int l, int r, const vector<ll>& pref, const vector<ll>& pref_ladder) {
	ll prefix = pref_ladder[r] - pref_ladder[l] - (pref[r] - pref[l]) * (l);
	return prefix;
}

// [L, R] -> get_suffix(L-1, R);
ll get_suffix(int l, int r, const vector<ll>& suff, const vector<ll>& suff_ladder) {
	int n = suff.size() - 1;
	ll suffix = suff_ladder[l] - suff_ladder[r] - (suff[l] - suff[r]) * (n - r);
	return suffix;
}

ll solve(int L, int R, const vector<ll>& a, const vector<ll>& pref, const vector<ll>& pref_ladder, const vector<ll>& suff, const vector<ll>& suff_ladder) {
	int M = (R + L) / 2;
	ll prefix = get_prefix(L - 1, M, pref, pref_ladder);
	ll suffix = get_suffix(((R - L + 1) % 2 == 0 ? M : M - 1), R, suff, suff_ladder);
	return prefix + suffix - (((R - L + 1) % 2 == 0) ? 0LL : 1LL *a[M - 1] * ((R - L + 2) / 2));
}

int32_t main() //R-L=1?
{
	useless;
	
	int t; cin >> t;
	int n, q;
	int L, R;
	while (t-- > 0) {
		cin >> n >> q;
		vector<ll>a(n);
		for (ll& x : a)
			cin >> x;
		vector<ll>pref(n + 1); // { 0, 1, 2, 3, 4, 5 }
		vector<ll>pref_ladder(n + 1); // { 0, 1, 3, 6, 10, 15 } 
		vector<ll>suff(n + 1);
		vector<ll>suff_ladder(n + 1);
		precalculate(a, pref, pref_ladder, suff, suff_ladder);
		/*
		cerr << pref[5] - pref[2];
		cerr << suff[0] - suff[3] << '\n';
		cerr << get_prefix(3, 5, pref, pref_ladder) << '\n';
		cerr << get_suffix(3, 5, suff, suff_ladder) << '\n';
		*/
		while (q-- > 0) {
			cin >> L >> R;
			cout << solve(L, R, a, pref, pref_ladder, suff, suff_ladder) << '\n';
		}
	}
	//int n = 5;
	//vector<ll>a = { 1, 1, 1, 1, 1 };
	//vector<ll>pref(n + 1); // { 0, 1, 2, 3, 4, 5 }
	//vector<ll>ladder(n + 1); // { 0, 1, 3, 6, 10, 15 } 
	//precalculate(a, pref, ladder);
	//for (int i = 0; i <= n; ++i) {
	//	cerr << ladder[i] << ' ';
	//}
	//cerr << '\n';
	//cerr << get_ladder(3, 5, pref, ladder) << '\n';
}

/*
1
5 10
1 1 1 1 1
1 4
1 2
3 5
4 5
4 4
1 2

6
2
4
2
1
2
*/
/*
1
6 3
-1 -2 -4 -8 -16 -32
2 5
*/