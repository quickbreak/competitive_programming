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


string wrong(int n) {
	str answer;

	vector<vector<ll>> d(n + 2, vector<ll>(n + 2));
	fori(j, 0, n + 2) {
		d[0][j] = 1;
	}
	fori(i, 1, n + 1) {
		fori(j, 1, n + 1) {
			d[i][j] = d[i][j - 1]; // сколько способов набрать сумму i без числа j
			if (j <= i)
				d[i][j] += d[i - j][j / 2]; // сколько способов набрать сумму i - j с числами,
			// которые хотя бы в 2 раза меньше j
			// cout << d[i][j] << ' ';
		}
		// cn;
	}
	cout << d[n][n];

	return answer;
	// cout << ans;
}


int main() // количество множеств (элементы уникальны) суммы n
{
	useless;

	// freopen("peacefulsets.in", "rt", stdin);
	// freopen("peacefulsets.out", "wt", stdout);

	int t, n; 
	t = 1;
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