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


vl a(3e5);
vi h(3e5);


int wrong(int n, int k)
{
	int ans = 0;
	fori(i, 0, n)
	{
		if (a[i] <= k)
			ans = 1;
	}
	if (n == 1) //если случай n==1
	{
		//cout << ans << '\n';
		return ans;
	}
	vl b(n + 1);
	b[0] = 0;
	fori(i, 0, n)
	{
		b[i + 1] = b[i] + a[i];
	}
	int l = 0;
	fori(r, 1, n)
	{
		if (h[r - 1] % h[r] == 0)
		{
			while (b[r + 1] - b[l] > k && l <= r)
			{
				l++;
			}
			ans = max(ans, r - l + 1);
		}
		else {
			l = r;
		}
	}
	//cout << ans << '\n';
	return ans;
}



int slow(int n, int k)
{
	int ans = 0;
	fori(i, 0, n)
	{
		if (a[i] <= k)
			ans = 1;
	}
	if (n == 1) //если случай n==1
	{
		//cout << ans << '\n';
		return ans;
	}
	/*vl b(n + 1);
	b[0] = 0;
	fori(i, 0, n)
	{
		b[i + 1] = b[i] + a[i];
	}
	*/
	fori(i, 0, n)
	{
		ll res = 0;
		int j = i;
		if (a[j] <= k)
		{
			ans = max(ans, 1);
			res = a[j];
		}
		else
			continue;
		j++;
		while (j<n && h[j-1] % h[j] == 0 && res + a[j] <= k)
		{
			res += a[j];
			ans = max(ans, j - i + 1);
			j++;
		}
	}

	return ans;
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int t, n, k; cin >> t;
	while (t--)
	{
		cin >> n >> k;
		fori(i, 0, n)
			cin >> a[i];
		fori(i, 0, n)
			cin >> h[i];
		/*if (slow(n, k) != wrong(n, k))
		{
			cout << "ATTENTION\n";
			cout << n << ' ' << k; 
			cn;
			cout << slow(n, k);
			cn;
			cout << wrong(n, k);
			cn;
			return 0;
		}*/
		cout << wrong(n, k); cn;
	}
	/*int t, n, k; 
	t = 1000;
	while (t--)
	{
		n = 1 + rand() % 10;
		k = 1 + rand() % 20;
		fori(i, 0, n)
			a[i] = 1 + rand() % 10;
		fori(i, 0, n)
			h[i] = 1 + rand() % 20;
		if (slow(n, k) != wrong(n, k))
		{
			cout << "ATTENTION\n";
			cout << n << ' ' << k;
			cn;
			fori(i, 0, n)
				cout << a[i] << ' ';
			cn;
			fori(i, 0, n)
				cout << h[i] << ' ';
			cn;
			cout << slow(n, k);
			cn;
			cout << wrong(n, k);
			cn;
			return 0;
		}
	}*/
}