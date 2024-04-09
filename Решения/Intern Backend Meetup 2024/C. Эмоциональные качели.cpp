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


string slow(str s) {

	vi a;
	int maxi = -1, mini = 30, number;
	for (char ch : s)
	{
		number = ch - 'a' + 1;
		a.push_back(number);
		maxi = max(maxi, number);
		mini = min(mini, number);
	}
	int n = a.size();
	vi min_pos, max_pos;
	fori(i, 0, n)
	{
		if (a[i] == maxi)
			max_pos.push_back(i);
		if (a[i] == mini)
			min_pos.push_back(i);
	}
	//sort(all(min_pos));
	//sort(all(max_pos));

	int ans_r = 0, ans_l = 0, ans = int(1e9), r, l;
	for (int l : min_pos)
	{
		fori(uk, 0, n) {

			if (a[uk] == maxi) {
				r = uk;
				if (abs(r - l) < ans)
				{
					ans = abs(r - l);
					ans_l = min(l, r);
					ans_r = max(l, r);
				}
			}

		}
	}

	for (int r : max_pos)
	{
		fori(uk, 0, n) {

			if (a[uk] == mini) {
				l = uk;
				if (abs(r - l) < ans)
				{
					ans = abs(r - l);
					ans_l = min(l, r);
					ans_r = max(l, r);
				}
			}

		}
	}

	str answer;
	fori(i, ans_l, ans_r + 1)
		answer += s[i];

	return answer;
}


string wrong(str s) {
	//str s; cin >> s;
	vi a;
	int maxi = -1, mini = 30, number;
	for (char ch : s)
	{
		number = ch - 'a' + 1;
		a.push_back(number);
		maxi = max(maxi, number);
		mini = min(mini, number);
	}
	int n = a.size();
	vi min_pos, max_pos;
	fori(i, 0, n)
	{
		if (a[i] == maxi)
			max_pos.push_back(i);
		if (a[i] == mini)
			min_pos.push_back(i);
	}
	sort(all(min_pos));
	sort(all(max_pos));

	int r, uk;
	int ans_r = 0, ans_l = 0, ans = int(1e9);
	for (int l : min_pos)
	{
		uk = int(lower_bound(all(max_pos), l) - max_pos.begin());
		if (uk == max_pos.size()) // если у них у всех позиция меньше нашей
			uk = max_pos.size() - 1;

		if (abs(max_pos[uk] - l) < ans || abs(max_pos[uk] - l) == ans && min(max_pos[uk], l) < ans_l) // отрезок короче нашли
		{
			ans = abs(max_pos[uk] - l);
			ans_l = min(max_pos[uk], l);
			ans_r = max(max_pos[uk], l);
		}
		--uk;
		if (uk >= 0) {
			if (abs(max_pos[uk] - l) < ans || abs(max_pos[uk] - l) == ans && min(max_pos[uk], l) < ans_l) // отрезок короче нашли
			{
				ans = abs(max_pos[uk] - l);
				ans_l = min(max_pos[uk], l);
				ans_r = max(max_pos[uk], l);
			}
		}
	}

	str answer;
	fori(i, ans_l, ans_r + 1)
		answer += s[i];

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