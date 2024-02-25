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

	int t; cin >> t;
	ll a, b;
	int n, k;
	while (t--) {
		cin >> n >> k;
		vector<string>a(n);
		string s;
		vector<int>b;
		ll cnt_digits = 0;
		fori(i, 0, n)
		{
			cin >> s;
			cnt_digits += s.size();
			int uk = s.size() - 1, cnt = 0;
			while (s[uk] == '0')
			{
				++cnt, --uk;
			}
			if (cnt > 0) {
				b.push_back(cnt);
			}
		}
		sort(all(b));
		ll can_be_removed = 0;
		for (int i = b.size() - 1; i >= 0; i -= 2) {
			can_be_removed += b[i];
		}
		if (cnt_digits - can_be_removed >= k + 1)
			cout << "Sasha\n";
		else cout << "Anna\n";
		
	}

}