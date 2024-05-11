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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	//префикс температур
	//для каждого сугроба v[i] бин искать первый день, в который >= v[i]+preft[i]
	vector<int>v(n);
	fori(i, 0, n)
	{
		cin >> v[i];
	}
	vector<int>t(n);
	fori(i, 0, n)
	{
		cin >> t[i];
	}
	vector<ll>preft(n + 1);
	preft[0] = 0;
	fori(i, 0, n)
	{
		preft[i + 1] = preft[i] + t[i];
	}
	int x, day;
	vector<int>d(n);
	vector<ll>dop(n);
	fori(i, 0, n)
	{
		x = v[i];
		if (x == 0)
			continue;
		d[i]++;
		day = int(lower_bound(preft.begin(), preft.end(), x + preft[i])-preft.begin())-1;
		if (day <= n-1)
		{
			d[day]--;
			dop[day] += x - (preft[day] - preft[i]);
		}
	}

	ll s = 0;
	fori(i, 0, n)
	{
		s += d[i];
		cout << t[i] * s + dop[i]<<' ';
	}
}