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
	ll a, b, c;
	while (--n >= 0) {
		cin >> a >> b >> c;
		if (a == 0 && b == 0) // если двое по нулям и третий не 1, то ггвп
		{
			if (c == 1) {

				cout << "Yes\n";
				continue;
			}
			else
			{
				cout << "No\n";
				continue;
			}
		}
		if (a == 0 && c == 0) // если двое по нулям и третий не 1, то ггвп
		{
			if (b == 1) {

				cout << "Yes\n";
				continue;
			}
			else
			{
				cout << "No\n";
				continue;
			}
		}
		if (c == 0 && b == 0) // если двое по нулям и третий не 1, то ггвп
		{
			if (a == 1) {

				cout << "Yes\n";
				continue;
			}
			else
			{
				cout << "No\n";
				continue;
			}
		}
		int chet = 0, nechet = 0;
		if (a % 2 == 0)
			chet++;
		else nechet++;
		if (b % 2 == 0)
			chet++;
		else nechet++;
		if (c % 2 == 0)
			chet++;
		else nechet++;
		if (chet == 2 && nechet == 1 || nechet == 2 && chet == 1)
			cout << "Yes\n";
		else cout << "No\n";
	}

}