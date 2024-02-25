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

	//freopen("input.in", "rt", stdin);
	//freopen("output.out", "wt", stdout);

	int n; ll max_weight;
	cin >> max_weight >> n;
	vi w(n);
	fori(i, 0, n)
		cin >> w[i];

	sort(all(w));
	vector<vector<ll>>d(max_weight + 1, vector<ll>(n));

	fori(i, 1, max_weight + 1) // вместимость i
	{
		fori(j, 0, n) // веса слитков w[j]
		{
			if (w[j] <= i) { //либо только слиток w[j]
				d[i][j] = w[j];

			}
			// либо макс. вес для вместимости <= i - w[j] ... + w[j]
			if (((i - w[j]) >= 0) && (j - 1 >= 0)) { 
				d[i][j] = max(d[i][j], d[i - w[j]][j - 1] + w[j]);

			}
			if (j - 1 >= 0) // либо максимальный вес, который можно собрать без участия слитка w[j]
				d[i][j] = max(d[i][j], d[i][j - 1]);

		}

	}
	ll ans = 0;
	fori(j, 0, n) {
		ans = max(ans, d[max_weight][j]);

	}
	cout << ans;
	/*cn;
	fori(i, 0, max_weight + 1)
	{
		fori(j, 0, n)
			cout << d[i][j] << ' ';
		cn;
	}*/
}