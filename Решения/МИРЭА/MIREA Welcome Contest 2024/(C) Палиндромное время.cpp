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

bool is_palindrome(const string& s) {
	int n = (int)s.size();
	for (int i = 0; i < n / 2; ++i) {
		if (s[i] != s[n - i - 1]) {
			return false;
		}
	}
	return true;
}


vector<string>pals;

int slow(const string& s1, const string& s2) {

	int answer = 0;
	int l = (int)(lower_bound(pals.begin(), pals.end(), s1) - pals.begin());
	int r = (int)(lower_bound(pals.begin(), pals.end(), s2) - pals.begin());
	if (s1 <= s2) {
		for (int i = l; i <= r && i < (int)pals.size(); ++i) {
			if (pals[i] >= s1 && pals[i] <= s2) {
				++answer;
			}
		}
	}
	else {
		for (int i = l; i < (int)pals.size(); ++i) {
			if (pals[i] >= s1) {
				++answer;
			}
		}
		for (int i = 0; i <= r && i < (int)pals.size(); ++i) {
			if (pals[i] <= s2) {
				++answer;
			}
		}
	}

	return answer;
}

int32_t main()
{
	useless;

	string h, m;
	string res;
	for (int i = 0; i <= 23; ++i) {
		h = to_string(i);
		if (h.size() == 1)
			h = "0" + h;
		for (int j = 0; j <= 59; ++j) {
			m = to_string(j);
			if (m.size() == 1)
				m = "0" + m;

			res = h + ":" + m;
			if (is_palindrome(res)) {
				pals.push_back(res);
			}
		}
	}
	cerr << pals.size() << '\n';
	for (auto p : pals)
		cerr << p << '\n';

	int t; cin >> t;
	string s1, s2;
	while (t-- > 0) {
		cin >> s1 >> s2;
		cout << slow(s1, s2) << '\n';
	}
}
/*
5
23:32 05:50
23:59 23:59
23:59 00:00
00:00 23:59
23:32 07:07

7
0
1
16
7
*/

/*
5
23:59 00:00
23:32 00:00
23:32 00:01
01:11 04:41
01:09 04:41

1
2
2
3
4
*/

/*
5
22:21 22:21
22:23 22:21
22:23 22:22
23:59 23:58
20:04 20:03

0
15
16
16
16
*/