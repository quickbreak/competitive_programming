﻿#include<algorithm>
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


string slow(str s) {



	str answer;

	return answer;
}


string wrong(str s) {
	

	str answer;

	return answer;
}


int main()
{
	useless;
	

	str s; cin >> s;
	cout << wrong(s);

	//rarf kxkxk jloehamoj
	/*str s = "aba";
	str s1 = slow(s);
	str s2 = wrong(s);
	if (s1 != s2) {
		cout << s1 << '\n' << s2;
	}
	else cout << "success";*/

	//fori(i, 0, 10000) {
	//	random_device rd;   // non-deterministic generator
	//	mt19937 gen(rd());  // to seed mersenne twister.
	//	uniform_int_distribution<> distn(1, 10); // distribute results between 1 and 6 inclusive.
	//	int n = distn(gen);
	//	/*uniform_int_distribution<> distk(1, n);
	//	int k = distk(gen);*/
	//	uniform_int_distribution<> distai(0, 25);
	//	str s;
	//	for (int i = 0; i < n; ++i) {
	//		s += char('a' + distai(gen));
	//	}
	//	str s1 = slow(s);
	//	str s2 = wrong(s);
	//	if (s1 != s2) {
	//		cout << s;
	//		cn;

	//		cout << s1 << '\n' << s2;
	//		break;
	//	}
	//}
	//cout << "\nsuccess?";
}