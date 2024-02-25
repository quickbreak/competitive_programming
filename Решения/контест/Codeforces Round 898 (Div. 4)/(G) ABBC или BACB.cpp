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

	int t, n;
	cin >> t;
	str s;
	bool f = false; //есть ли В до последовательности А?
	int ukb;
	while (t--)
	{
		cin >> s;
		ll ans = 0;
		n = s.size();	
		f = false;
		ukb = -1;
		vi a;
		int res = 0, cnt = 0;
		fori(i, 0, n)
		{
			if (s[i] == 'B')
			{
				res = i - ukb - 1;
				a.push_back(res);
				ukb = i;

				if (i > 0 && s[i - 1] == 'A' or i < n - 1 && s[i + 1] == 'A')
					cnt++;
			}
		}
		a.push_back(n-ukb-1);
		sort(a.rbegin(), a.rend());
		//fori(i, 0, a.size())
			//cout << a[i] << ' ';
		//cout << cnt; cout << '\n';
		int m = a.size();
		int i = 0;
		while (i < m && cnt>0)
		{
			ans += a[i];
			i++; cnt--;
		}
		cout << ans << '\n';
	}
}