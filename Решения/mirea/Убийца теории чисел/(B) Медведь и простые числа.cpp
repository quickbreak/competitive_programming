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


const int NMAX = (int)1e7 + 100;
vector<int>first_div(NMAX), powerA(NMAX), powerB(NMAX);


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


void wrong(vector<int>& a, vector<pair<int, int>>& b, int n, int m) {
	//str answer;
	vector<int>pref(NMAX);
	precalc();
	int p;
	for (auto& x : a) {
		while (x > 1) {
			p = first_div[x];
			++pref[p]; // ещё одно число (х) делится на простое p
			while (x % p == 0)
				x /= p;
		}
	}
	fori(i, 2, NMAX) {
		pref[i] = pref[i - 1] + pref[i]; // сколько чисел из а делятся на простые из диапазона 2..i
	}

	for (auto pa: b) {
		cout << pref[min(NMAX - 1, pa.second)] - pref[min(NMAX - 1, pa.first) - 1] << '\n';
		// гений на контестмене поставил l, r <= 2e9
	}

	// cout << ans;
	//return answer;
}


int main() {
	useless;


	int n, m; cin >> n;
	vector<int>a(n);
	fori(i, 0, n)
		cin >> a[i];
	cin >> m;
	vector<pair<int, int>>b(m);
	fori(i, 0, m)
		cin >> b[i].first >> b[i].second;
	wrong(a, b, n, m);


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