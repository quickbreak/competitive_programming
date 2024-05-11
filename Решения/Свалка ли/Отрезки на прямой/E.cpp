#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<stack>
#include<queue>
#include<set>
#include<map>
using namespace std;
int main()
{
	int n;
	cin >> n;
	//int l, r;
	//vector<pair<pair<int, int>, int>>v;
	//pair<pair<int, int>, int>p, k;
	pair<pair<int, int>, int>rmin;
	pair<pair<int, int>, int>lmax;
	lmax.first.first = -1;
	lmax.first.second = -1;
	lmax.second = -1;
	rmin.first.first = 100;
	rmin.first.second = 100;
	rmin.second = 100;
	int a, b, c, e, f, g;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b >> c >> e >> f >> g;
		if (a!=e || b!=f || c!=g)
		{
			if (a > lmax.first.first || a == lmax.first.first && b > lmax.first.second || a == lmax.first.first && b == lmax.first.second && c > lmax.second)
			{
				lmax.first.first = a;
				lmax.first.second = b;
				lmax.second = c;
			}
			if (e < rmin.first.first || e == rmin.first.first && f < rmin.first.second || e == rmin.first.first && f == rmin.first.second && g < rmin.second)
			{
				rmin.first.first = e;
				rmin.first.second = f;
				rmin.second = g;
			}
		}
	}
	a = lmax.first.first;
	b = lmax.first.second;
	c = lmax.second;
	e = rmin.first.first;
	f = rmin.first.second;
	g = rmin.second;
	if (a < e || a == e && b < f || a == e && b == f && c == g)
		cout << ((e - a) * 3600 + (f - b) * 60 + g - c);
	else cout << '0';
}