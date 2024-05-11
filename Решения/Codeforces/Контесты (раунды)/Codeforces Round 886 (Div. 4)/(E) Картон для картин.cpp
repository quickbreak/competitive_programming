#include<iostream>
#include<cstdio>
#include<cmath>
#include<set>
#include<vector>
#include<algorithm>
#include<stack>
#include<map>

#define fori(it,a,b) for(int it=a;it<b;it++)

using namespace std;

using ll = long long;
using str = string;
using ld = long double;
using vi = vector<int>;
using vl = vector<long long>;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//cout<<precision<<fixed;


	/*str s = "asvkdxbjc";
	vi a(10);
	a[0] = -2; a[9] = -3;
	for (char ch : s)
		cout << ch;
	cout << endl;
	for (int x : a)
		cout << x;
	cout << endl;

	int p = (5 > 2 ? 1 : 0);
	cout << p << endl;


	double a = -5.67675;
	cout.precision(5);
	cout << a;*/
	int t, n, l, r, m;
	long long summa, c;
	cin >> t;
	bool warn = false;
	while (t--)
	{
		cin >> n >> c;
		vl s(n);
		fori(i,0,n)
			cin >> s[i];
		l = 1; r = 1e9;//1å9
		while (r - l > 1)
		{
			m = (r + l) / 2;
			summa = 0;
			warn = false;
			for (ll len : s)
			{
				summa += (len + 2 * m) * (len + 2 * m);
				if (summa > c)
				{
					warn = true;
					break;
				}
			}
			if (warn)
			{
				r = m;
				continue;
			}
			if (summa > c)
				r = m;
			else l = m;
		}
		cout << l << '\n';
	}
}