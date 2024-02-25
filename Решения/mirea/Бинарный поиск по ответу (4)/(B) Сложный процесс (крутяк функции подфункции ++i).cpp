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


int check(const vi& a, int len, int cnt) //           const,                     
{//можно массив по-другому назвать, не обязательно как в main
	int nZeros = 0;
	auto add = [&](int x) {
		if (x == 0)
			nZeros++;
		};
	auto rem = [&](int x)
		{
			if (x == 0)
				nZeros--;
		};

	int i = 0;
	while (i < len)
	{
		add(a[i++]);
	}
	int pos = 0;
	if (nZeros <= cnt)
		return pos;

	while (i < a.size())
	{
		rem(a[pos++]);
		add(a[i++]);
		if (nZeros <= cnt)
			return pos;
	}
	return -1;
}


int main()
{
	useless;

	int n, k; cin >> n >> k;
	vi a(n);
	fori(i, 0, n)
		cin >> a[i];
	int l = 0, r = n + 1, m;
	while (r - l > 1)
	{
		m = (r + l) / 2;
		if (check(a, m, k) != -1)
		{
			l = m;
		}
		else r = m;
	}
	int pos = check(a, l, k);
	cout << l; cn;
	fori(i, 0, n)
		cout << (i >= pos && i < pos + l ? 1 : a[i]) << ' ';

}