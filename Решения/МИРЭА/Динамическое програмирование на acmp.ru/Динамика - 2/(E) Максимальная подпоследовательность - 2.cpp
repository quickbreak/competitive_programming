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
using pii = pair<int, int>;

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

//int inf = (int)1e9 + 7;

int32_t main()
{
	useless;

	int n; cin >> n;
	vi a(n);
	cin >> a[0];
	int k, b, m; cin >> k >> b >> m;
	fori(i, 1, n)
		a[i] = (a[i - 1] * k % m + b) % m;

	// d[i].first = минимальный элемент, которым могла оканчиваться подпосл. длины i
	// d[i].second = индекс этого элемента в массиве а
	//vector d(n + 1, pii(1000000001, -1));
	vector<pii>d;
	vi parent(n + 1); // parent[i] = индекс родителя a[i]-того
	fori(i, 0, n) {
		int x = a[i];
		int uk = lower_bound(all(d), pii(x, -1)) - d.begin();
		if (uk >= 0 && uk < d.size())
		{
			d[uk] = min(d[uk], { x, i });
			parent[i] = d[max(uk - 1, 0)].second;
		}
		else if (uk >= d.size())
		{
			d.push_back({ x, i });
			parent[i] = d[max((int)d.size() - 2, 0)].second;
		}
		else cout << "loser\n";
		assert(uk >= 0);
	}

	vi res;
	res.push_back(d[d.size() - 1].first); // с последнего я гарантированно смогу найти
	int last = d[d.size() - 1].second;
	while (res.size() < d.size()) {
		res.push_back(a[parent[last]]);
		last = parent[last];
	}
	reverse(all(res));
	for (int y : res)
		cout << y << ' ';

}