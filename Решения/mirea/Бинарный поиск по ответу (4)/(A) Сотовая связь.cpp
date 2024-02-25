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

#define fori(it, a, b) for(int it = a; it < b; it++)
#define all(x) (x).begin(),(x).end()
#define cn cout << '\n'
#define minel(v) *min_element(v.begin(), v.end());
#define maxel(v) *max_element(v.begin(), v.end());
#define sortv(v) sort(v.begin(), v.end());
#define forl(a, k, b) for(long long a = k; a < b; a++)
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


bool check(vi &b, int x, ll r)

{
	int uk = lower_bound(b.begin(), b.end(), x) - b.begin();
	if (uk != b.size() && (b[uk] - x) <= r)
		return true;

	if (uk - 1 > -1 && uk - 1 < b.size() && (x - b[uk - 1]) <= r)
		return true;
	return false;
}


int main()
{
	useless;

	int n, k; cin >> n >> k;
	vi a(n);
	fori(i, 0, n)
		cin >> a[i];
	vi b(k);
	fori(i, 0, k)
		cin >> b[i];

	ll l = -1, r = 1000000000000000004, m;
	while (r - l > 1)
	{
		m = l + (r - l) / 2;
		bool flag = false;
		fori(i, 0, n)
		{
			if (check(b, a[i], m))
			{
				flag = true;
			}
			else
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			r = m;
		}
		else l = m;
	}
	assert(r != 1000000000000000004);
	cout << r;
}