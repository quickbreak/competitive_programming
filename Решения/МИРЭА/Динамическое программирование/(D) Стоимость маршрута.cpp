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
	//freopen("king2.in", "rt", stdin);
	//freopen("king2.out", "wt", stdout);
	int n = 8, m = 8;
	vector<vector<ll>> a(n + 2, vector<ll>(m + 2));
	fori(i, 0, n)
	{
		fori(j, 0 + 2, m + 2)
		{
			cin >> a[i][j];
		}
	}
	//cn; cn;
	vector<vector<ll>> d(n+2, vector<ll>(m + 2));
	fori(j, 0 + 3, m + 2)
	{
		d[n - 1][j] = d[n - 1][j - 1] + a[n - 1][j];
	}
	for (int i = n - 1 - 1; i >= 0; --i)
	{
		d[i][0 + 2] = d[i + 1][0 + 2] + a[i][0 + 2];
	}
	for (int i = n - 1 - 1; i >= 0; --i)
	{
		fori(j, 0 + 2 + 1, m + 2)
		{
			d[i][j] = min(d[i + 1][j - 1], min(d[i + 1][j], d[i][j - 1])) + a[i][j];
		}
	}
	/*for (int i = 0; i < n; ++i)
	{
		fori(j, 0 + 2, m + 2)
		{
			cout << d[i][j] << ' ';
		}
		cn;
	}*/

	cout << d[0][m + 1];
}