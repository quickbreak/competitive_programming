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
	
	int n; cin >> n;
	int year; cin >> year;
	int x; str s;
	map<string, int>mp;
	mp["January"] = 1;
	mp["February"] = 2;
	mp["March"] = 3;
	mp["April"] = 4;
	mp["May"] = 5;
	mp["June"] = 6;
	mp["July"] = 7;
	mp["August"] = 8;
	mp["September"] = 9;
	mp["October"] = 10;
	mp["November"] = 11;
	mp["December"] = 12;
	vector<int>days_cnt = { 31, 28 + (year % 400 == 0 || year % 4 == 0 && year % 100 != 0), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	vector<int>pref = { 0 };
	fori(i, 0, 12)
		pref.push_back(pref.back() + days_cnt[i]);

	vector<int>holidays_cnt(7);
	vector<pair<int, str>>in;
	int days;
	fori(i, 0, n) {
		cin >> x >> s;
		in.push_back(pair<int, str>(x, s));
	}
	vector<string>days_of_week = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	int day_of_week;
	cin >> s;
	fori(i, 0, 7)
		if (days_of_week[i] == s)
		{
			day_of_week = i;
			holidays_cnt[i]++; // этот день 53 раза
			if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
				holidays_cnt[(i + 1) % 7]++; // если високосный, то и этот
		}
	for(auto p:in) {
		x = p.first;
		s = p.second;
		days = day_of_week + pref[mp[s] - 1] + x - 1;
		--holidays_cnt[days % 7];
	}
	str best, worst;
	int bestc = -int(1e9), worstc = int(1e9);
	fori(i, 0, 7)
	{
		if (holidays_cnt[i] > bestc)
		{
			bestc = holidays_cnt[i];
			best = days_of_week[i];
		}
		if (holidays_cnt[i] < worstc)
		{
			worstc = holidays_cnt[i];
			worst = days_of_week[i];
		}

	}
	cout << best << ' ' << worst;
}