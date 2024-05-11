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


int main()
{
	useless;

	//int n, k; 
	//cin >> n >> k;
	////scanf("%d %d", &n, &k);
	//vi a(n);
	//vi d(1e6 + 1);
	//vi b(n + 1);
	//fori(i, 0, n)
	//{
	//	//scanf("%d", &a[i]);
	//	cin >> a[i];
	//	b[i + 1] = b[i];
	//	if (!d[a[i]])
	//		b[i + 1]++;
	//	d[a[i]]++;
	//}
	//int resl = 1, resr = n, ans = 1;
	//b.push_back(1e7);
	////ans = 0;
	//fori(i, 1, n - k + 1)
	//{
	//	int uk = upper_bound(b.begin(), b.end(), b[i] + k - 1) - b.begin(); //n+1
	//	if (uk - i > ans)
	//	{
	//		ans = uk - i;
	//		resl = i;
	//		resr = uk - 1;
	//	}
	//}
	////printf("%d %d", resl, resr);
	//cout << resl << ' ' << resr;

	int n, k;
	//scanf("%d %d", &n, &k);
	cin >> n >> k;
	vi a(n);
	vi dict(1e6 + 1);
	vi b(n + 1);
	fori(i, 0, n)
	{
		//scanf("%d", &a[i]);
		cin >> a[i];
	}
	int resl = -1, resr = -1, ans = 0;
	b.push_back(1e7);
	//ans = 0;
	int l = 0, r = 0, cnt = 0;
	while (r < n)
	{
		if (dict[a[r]] == 0)
			cnt++;
		dict[a[r]]++;
		while (cnt > k)
		{
			dict[a[l]]--;
			if (dict[a[l]] == 0)
				cnt--;
			l++;
		}
		if (r - l + 1 > ans)
		{
			ans = r - l + 1;
			resr = r + 1;
			resl = l + 1;
		}
		r++;
	}
	//printf("%d %d", resl, resr);
	cout << resl << ' ' << resr;
}
/*
5 2
1 1 2 2 3
*/