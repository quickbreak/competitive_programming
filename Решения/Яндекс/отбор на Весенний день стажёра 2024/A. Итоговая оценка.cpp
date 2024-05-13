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


int32_t main()
{
	useless;
	
	str s; cin >> s;
	double worst_mark = 30, total_score = 0;
	for (char word : s) {
		worst_mark = min(worst_mark, double('Z' - word + 1));
		total_score += double('Z' - word + 1);
	}
	double mid = total_score / double(s.size());	
	mid = round(mid);
	cout << char('Z' - min(mid, worst_mark + 1) + 1);
}