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
	while (t--)
	{
		cin >> n;
		vi a(n);
		int minx=10, uk=-1;
		fori(i, 0, n)
		{
			cin >> a[i];
			if (a[i] < minx)
			{
				minx = a[i];
				uk = i;
			}
		}
		a[uk]++;
		ll p = 1;
		fori(i, 0, n)
			p *= a[i];
		cout << p<<'\n';
	}
}