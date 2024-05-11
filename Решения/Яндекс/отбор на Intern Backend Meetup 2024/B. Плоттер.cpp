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
	
	int n, m; cin >> n >> m;
	int q; cin >> q;
	int curr_x = 0, curr_y = 0, next_x, next_y;
	char command;
	set<pair<pair<int, int>, pair<int, int>>>st;
	while (--q >= 0) {
		cin >> command;
		if (command == 'U')
			next_x = curr_x, next_y = curr_y + 1;
		else if (command == 'D')
				next_x = curr_x, next_y = curr_y - 1;
		else if (command == 'R')
			next_x = curr_x + 1, next_y = curr_y;
		else if (command == 'L')
			next_x = curr_x - 1, next_y = curr_y;

		st.insert({ {curr_x, curr_y}, {next_x, next_y} });
		st.insert({ {next_x, next_y}, {curr_x, curr_y} });

		curr_x = next_x;
		curr_y = next_y;
	}
	cout << st.size() / 2;
}