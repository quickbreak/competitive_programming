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

#define fori(it, a, b) for(int it = a; it < b; ++it)
#define all(x) (x).begin(),(x).end()
#define cn cout << '\n'
#define minel(v) *min_element(v.begin(), v.end());
#define maxel(v) *max_element(v.begin(), v.end());
#define sortv(v) sort(v.begin(), v.end());
#define forl(a, k, b) for(long long a = k; a < b; ++a)
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


int main()
{
	useless;
	//freopen("lepus.in", "rt", stdin);
	//freopen("lepus.out", "wt", stdout);
	int n; cin >> n;
	vector<char> a(n);
	fori(i, 0, n)
		cin >> a[i];

	vi d(n);
	//d[0] = a[0];
	//d[1] = max(d[0], 0) + a[1];
	fori(i, 0, n)
	{
		if (i >= 5)
			d[i] = max(d[i - 5], max(d[i - 1], d[i - 3]));
		else if (i >= 3)
			d[i] = max(d[i - 1], d[i - 3]);
		else if (i >= 1)
			d[i] = d[i - 1];
		else d[i] = 0;

		if (a[i] == 'w')
			d[i] = -1001;
		else if (a[i] == '.')
			d[i] += 0;
		else d[i]++;
	}
	cout << max(d[n - 1], -1);
}