#include<algorithm>
#include<any>
#include<cassert>
#include<cmath>
#include<cstdio>
#include<deque>
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

	int n, k;
	cin >> n >> k;
	vector<ll>a(n);
	vector<int>cnt(k + 1);
	fori(i, 0, n)
	{
		cin >> a[i];
	}
	int l = 0;
	int ans = 1e9, resl = -1, resr = -1;
	set<int>st;
	st.insert(a[0]);
	fori(r, 0, n)
	{
		++cnt[a[r]]; 
		st.insert(a[r]);
		if (a[r] == a[l])
		{
			while (cnt[a[l]] > 1)
			{
				--cnt[a[l]];
				++l;
			}
		}
		if (st.size() == k && r - l < ans) {
			ans = r - l + 1;
			resl = l;
			resr = r;
		}
	}

	cout << resl + 1 << ' ' << resr + 1;
	
}