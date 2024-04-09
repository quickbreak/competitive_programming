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
	
	str s;
	cin >> s;
	int t1_f = int(s[0]) - 48;
	int t2_f = int(s[2]) - 48;

	cin >> s;
	int t1_s = int(s[0]) - 48;
	int t2_s = int(s[2]) - 48;

	int typee; cin >> typee;

	if (t1_f + t1_s > t2_f + t2_s)
		cout << 0;
	else if (t1_f + t1_s < t2_f + t2_s)
	{
		if (typee == 1) // первая игра была дома
		{
			if ((t2_f + t2_s - (t1_f + t1_s)) + t1_s > t2_f)
				cout << t2_f + t2_s - (t1_f + t1_s);
			else cout << t2_f + t2_s - (t1_f + t1_s) + 1;
		}
		else { // первая игра была в гостях
			if (t1_f > t2_s) // мы в гостях забили больше, чем они в гостях забили
				cout << t2_f + t2_s - (t1_f + t1_s);
			else cout << t2_f + t2_s - (t1_f + t1_s) + 1;
		}
	}
	else {
		if (typee == 1) // первая игра была дома
		{
			if (t1_s > t2_f) // мы в гостях уже забили больше, чем они в гостях забили
				cout << 0;
			else cout << 1;
		}
		else { // первая игра была в гостях
			if (t1_f > t2_s) // мы в гостях забили больше, чем они в гостях забили
				cout << 0;
			else cout << 1;
		}

	}

}