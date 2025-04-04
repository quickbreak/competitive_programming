#include<algorithm>
#include<any>
#include<cassert>
#include<cmath>
#include<cstdio>
#include<deque>
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


string slow(const vector<long long>& a, int n) {
	str answer;


	return answer;
}


void wrong(int n) {
	// str answer;
	vector<pair<int,int>>a, b, c;
	int x;
	fori(i, 0, n) {
		cin >> x;
		a.push_back({ x, i });
	}
	sort(all(a));
	fori(i, 0, n) {
		cin >> x;
		b.push_back({ x, i });
	}
	sort(all(b));
	fori(i, 0, n) {
		cin >> x;
		c.push_back({ x, i });
	}
	sort(all(c));
	int ans = 0;
	fori(i, n - 3, n)
	{
		fori(j, n - 3, n)
		{
			fori(k, n - 3, n)
			{
				if (a[i].second != b[j].second && a[i].second != c[k].second && b[j].second != c[k].second)
					ans = max(ans, a[i].first + b[j].first + c[k].first);
			}
		}
	}
	// return answer;
	cout << ans; cn;
}


int main()
{
	useless;


	int t, n; cin >> t;
	while (t--) {
		cin >> n;
		wrong(n);
	}


	//fori(i, 0, 1000) {
	//	random_device rd;   // non-deterministic generator
	//	mt19937 gen(rd());  // to seed mersenne twister.
	//	uniform_int_distribution<> distn(1, 10); // distribute results between 1 and 6 inclusive.
	//	int n = distn(gen);
	//	uniform_int_distribution<> distk(1, n);
	//	int k = distk(gen);
	//	uniform_int_distribution<> distai(-10, 10);
	//	vector<long long>a(n);
	//	for (int i = 0; i < n; ++i) {
	//		a[i] = distai(gen);

	//	}
	//	str s1 = slow();
	//	str s2 = wrong();
	//	if (s1 != s2) {
	//		cout << n;
	//		cn;

	//		cout << s1 << '\n' << s2;
	//		break;
	//	}
	//}
}