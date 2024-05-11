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


int check(const vi& a, int len, int cnt)
{
	int pos = 0, i = 0, res = 0, n = a.size();
	while (i < n)
	{
		bool f = false;
		while (i < n && a[i] - pos + 1 <= len)
		{
			i++;
			f = true;
		}
		if (f)
		{
			res++;
			pos = a[i - 1] + 1;
		}
		else return 1000000000;
	}
	return res;
}


int main()
{
	useless;

	int k; cin >> k;
	vi a;
	str s;
	getline(cin, s);
	getline(cin, s);
	int n = s.size();
	fori(i, 0, n)
	{
		if (s[i] == ' ' || s[i] == '-')
		{
			a.push_back(i);
		}
	}
	a.push_back(n - 1);
	int l = 0, r = n + 1, m;
	while (r - l > 1)
	{
		m = (r + l) / 2;
		if (check(a, m, k) <= k)
		{
			r = m;
		}
		else l = m;
	}
	cout << r; 
}