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


const int NMAX = (int)5e6 + 100;
vector<int>first_div(NMAX);
vector<ll>pref(NMAX + 1);


string slow(const vector<long long>& a, int n) {
	str answer;


	return answer;
}


void precalc() {

	for (int i = 2; i * i < NMAX; ++i) { // до корня, потому что минимальное рассматриваемое 
		// составное число, при условии, что i - простое, - i * i, то есть NMAX
		if (first_div[i] == 0) { // i - простое
			for (int j = i * i; j < NMAX; j += i) { // от i * i, потому что
				// (2 * i) % 2 == 0 (рассмотрено ранее), (3 * i) % 3 == 0 (тоже рассмотрено), 
				// и т. д. до i * i
				if (first_div[j] == 0) // это первый делитель числа
					first_div[j] = i;

			}
		}
	}

	for (int i = 1; i < NMAX; ++i) { // мы не заполнили для самих простых чисел
		if (first_div[i] == 0)
			first_div[i] = i;
	}

}


void prefix() {
	precalc();
	int x, p;
	ll res = 0;
	fori(i, 1, NMAX) {
		x = i;
		res = 0;
		while (x > 1) {
			p = first_div[x];
			++res;
			x /= p;
		}
		pref[i] = pref[i - 1] + res;
	}
}


void wrong(int a, int b) {
	//str answer;
	assert(a >= b);
	cout << pref[a] - pref[b] << '\n';

	//return answer;
}


int main() {
	useless;


	int a, b, t; cin >> t;
	prefix();
	while (--t >= 0) {
		cin >> a >> b;
		wrong(a, b);
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