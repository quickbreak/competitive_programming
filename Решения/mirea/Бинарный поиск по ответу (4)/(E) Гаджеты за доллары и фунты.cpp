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


bool check(const vector<pair<ll, int>>& a, const vector<pair<ll, int>>& b, const vector<pair<ll, int>>&D, const vector<pair<ll, int>>&F, int day, int k, int s)
{
	int n = a.size();
	int mD = a[day].first, mF = b[day].first;
	int uk1 = 0, uk2 = 0;
	ll res = 0;
	int cnt = 0;
	while (cnt < k)
	{
		if (uk1 < D.size())
		{
			if (uk2 < F.size())
			{
				if (D[uk1].first * mD < F[uk2].first * mF)
				{
					res += D[uk1++].first * mD;
				}
				else
				{
					res += F[uk2++].first * mF;
				}
			}
			else {
				res += D[uk1++].first * mD;
			}
		}
		else {
			res += F[uk2++].first * mF;
		}

		cnt++;
	}
	if (res <= s)
		return true;
	else return false;
}


int main()
{
	useless;

	int n, m, k, s; cin >> n >> m >> k >> s;
	vector<pair<ll, int>> a(n), b(n);
	int kurs;
	cin >> a[0].first;
	a[0].second = 0;
	fori(i, 1, n)
	{
		cin >> kurs;
		if (kurs >= a[i - 1].first)
		{
			a[i] = a[i - 1];
		}
		else a[i] = { kurs, i };
	}
	cin >> b[0].first;
	b[0].second = 0;
	fori(i, 1, n)
	{
		cin >> kurs;
		if (kurs >= b[i - 1].first)
		{
			b[i] = b[i - 1];
		}
		else b[i] = { kurs, i };
	}
	vector<pair<ll, int>>D, F;
	int x, y;
	fori(i, 0, m)
	{
		cin >> x >> y;
		if (x == 1)
			D.push_back({ y, i });
		else F.push_back({ y, i });
	}
	sort(D.begin(), D.end());
	sort(F.begin(), F.end());
	int l = -1, r = n, day;
	while (r - l > 1)
	{
		day = (r + l) / 2;
		if (check(a, b, D, F, day, k, s))
		{
			r = day;
		}
		else l = day;
	}
	if (r == n)
	{
		cout << -1;
		return 0;
	}
	else {
		cout << r + 1; cn;
		day = r;
		int mD = a[day].first, mF = b[day].first;
		int d1 = a[day].second + 1, d2 = b[day].second + 1;
		int uk1 = 0, uk2 = 0;
		ll res = 0;
		int cnt = 0;
		while (cnt < k)
		{
			if (uk1 < D.size())
			{
				if (uk2 < F.size())
				{
					if (D[uk1].first * mD < F[uk2].first * mF)
					{
						res += D[uk1].first * mD;
						cout << D[uk1++].second + 1 << ' ' << d1; cn;
					}
					else
					{
						res += F[uk2].first * mF;
						cout << F[uk2++].second + 1 << ' ' << d2; cn;
					}
				}
				else {
					res += D[uk1].first * mD;
					cout << D[uk1++].second + 1 << ' ' << d1; cn;
				}
			}
			else {
				res += F[uk2].first * mF;
				cout << F[uk2++].second + 1 << ' ' << d2; cn;
			}
			cnt++;
		}
	}
}