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


bool check(const vector<int>& left, vector<int>& right, int k)
{
	int n = left.size();
	int ukleft = 0, ukright = 0; //                                  ,                        
	//                                      k                                           
	//           ,                                              
	fori(i, 0, n)
	{
		ukright = min(ukright + k, right[i]);
		ukleft = max(ukleft - k, left[i]);
		if (ukright < left[i] || ukleft > right[i])
			return false;
	}
	return true;
}


int main() //
{
	useless;

	//freopen("lepus.in", "rt", stdin);
	//freopen("lepus.out", "wt", stdout);

	int t, n; cin >> t;
	while (t-- > 0)
	{
		cin >> n;
		vector<int>a(n);
		int cnt = 0;
		cin >> a[0];
		int pos = n;
		fori(i, 1, n)
		{
			cin >> a[i];
			if (a[i] < a[i - 1])
			{
				cnt++;
				pos = i;
			}
		}
		if (cnt == 0)
		{
			cout << 0; cn;
			continue;
		}
		int ans = 1e9;
		if (cnt == 1 && a[n - 1] <= a[0])
		{
			ans = min(n - pos, 1 + pos + 1);

		}
		cnt = 0;
		fori(i, 1, n)
		{
			if (a[i] > a[i - 1])
			{
				cnt++;
				pos = i;
			}
		}
		if (cnt == 0)
		{
			cout << 1; cn;
			continue;
		}
		if (cnt == 1 && a[n - 1] >= a[0])
		{
			ans = min(ans, min(n - pos + 1, 1 + pos));

		}
		cout << ((ans == 1e9) ? - 1 : ans); cn;

	}

}