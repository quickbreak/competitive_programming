#include<algorithm>
#include<any>
#include<cassert>
#include<cmath>
#include<cstdio>
#include<deque>
#include<functional>
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
//define int long long;

using namespace std;

using ll = long long;
using str = string;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vector<int>>;

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


int32_t main()
{
	useless;
	// дано поле из 1 и 0
	// найти квадрат максимальной площади
	// 1110
	// 1111
	// 1111
	// 0111
	// идея:
	// рассмотрим длину квадрата в клетке i-1, j-1
	// а также длину КВАДРАТОВ в клетке i-1, j и i, j-1
	// 
	int n; cin >> n;
	vector a(n + 1, vector (n + 1, 0));
	string s;
	fori(i, 1, n + 1) {
		cin >> s;
		fori(j, 1, n + 1) {
			a[i][j] = (s[j - 1] == '1' ? 1 : 0);
		}
	}
	int ans = 0;
	vector d(n + 1, vector (n + 1, 0));
	fori(i, 1, n + 1) {
		fori(j, 1, n + 1)
		{
			if (a[i][j] == 0) {
				continue;
			}
			d[i][j] = min(d[i-1][j], d[i][j-1]);
			d[i][j] = min(d[i][j], d[i - 1][j - 1]) + 1;
			ans = max(d[i][j], ans);
		}
	}
	cout << ans * ans;

}
/*
7
1101101
1111110
1011100
0011100
1000010
1100111
1001110

--9

*/