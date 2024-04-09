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
using vvl = vector<vector<long long>>;

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

	vector<vector<char>>a(9, vector<char>(9));
	fori(i, 0, 8)
	{
		fori(j, 0, 8)
			cin >> a[i][j];
	}
	fori(i, 0, 8)
	{
		fori(j, 0, 8)
		{
			if (a[i][j] == 'R') {
				fori(k, j + 1, 8) {
					if (a[i][k] == '*' || a[i][k] == '#')
						a[i][k] = '#';
					else break;
				}
				fori(k, 1, j + 1) {
					if (a[i][j - k] == '*' || a[i][j - k] == '#')
						a[i][j - k] = '#';
					else break;
				}
				fori(k, i + 1, 8) {
					if (a[k][j] == '*' || a[k][j] == '#')
						a[k][j] = '#';
					else break;
				}
				fori(k, 1, i + 1) {
					if (a[i - k][j] == '*' || a[i - k][j] == '#')
						a[i - k][j] = '#';
					else break;
				}
			}
			else if (a[i][j] == 'B') {
				fori(k, 1, 8 - max(i, j)) {
					if (a[i + k][j + k] == '*' || a[i + k][j + k] == '#')
						a[i + k][j + k] = '#';
					else break;
				}
				fori(k, 1, min(i, j) + 1) {
					if (a[i - k][j - k] == '*' || a[i - k][j - k] == '#')
						a[i - k][j - k] = '#';
					else break;
				}

				fori(k, 1, min(i, 7 - j) + 1) {
					if (a[i - k][j + k] == '*' || a[i - k][j + k] == '#')
						a[i - k][j + k] = '#';
					else break;
				}
				fori(k, 1, min(j, 7 - i) + 1) {
					if (a[i + k][j - k] == '*' || a[i + k][j - k] == '#')
						a[i + k][j - k] = '#';
					else break;
				}
			}
		}
	}
	int ans = 0;
	fori(i, 0, 8)
	{
		fori(j, 0, 8)
		{
			//cout << a[i][j];
			if (a[i][j] == '*')
				++ans;
		}
		//cn;
	}
	cout << ans;
}