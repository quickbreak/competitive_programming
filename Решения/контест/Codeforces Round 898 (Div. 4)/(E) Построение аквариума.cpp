#include<iostream>
#include<cstdio>
#include<cmath>
#include<set>
#include<vector>
#include<algorithm>
#include<stack>
#include<map>

#define fori(it,a,b) for(int it=a;it<b;it++)
#define all(x) (x).begin(),(x).end()

using namespace std;

using ll = long long;
using str = string;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n, x;
	cin >> t;
	while (t--)
	{
		cin >> n >> x;
		vi a(n);
		fori(i, 0, n)
			cin >> a[i];
		ll l = 1, r = 2e9+2, m;
		while (r - l > 1)
		{
			m = (r + l) / 2;
			ll res = 0;
			fori(i, 0, n)
			{
				if (m > a[i])
					res += m - a[i];
				if (res > x)
					break;
			}
			if (res > x)
				r = m;
			else l = m;
		}
		cout << l << '\n';
	} 
/*
1
1 1000000000
1000000000
*/
}