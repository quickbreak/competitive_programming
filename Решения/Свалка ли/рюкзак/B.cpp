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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	double s;
	cin >> s >> n;
	long long sum = 0;
	double a, b;
	vector<pair<double, double>>v;
	vector<double>weight(n);
	vector<double>price(n);
	pair<double, double>p;
	for (int i = 0; i < n; i++)
	{
		cin >> weight[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> price[i];
	}
	long double cost = 0;
	for (int i = 0; i < n; i++)
	{
		if (weight[i] != 0)
		{
			p.first = price[i] / weight[i];
			p.second = weight[i];
			v.push_back(p);
		}
		else
			cost += price[i];
	}
	sort(v.begin(), v.end());
	long long w = 0;
	bool f = false;
	for (int i = v.size() - 1; i > -1 && w < s; i--)
	{
		if (w + v[i].second > s)
		{
			cost += (s - w) * v[i].first;
			w = s;
			f = true;
		}
		else
		{
			w += v[i].second;
			cost += v[i].second * v[i].first;
		}
	}
	long long g = cost;
	if (g != cost)
	{
		g++;
	}
	cout << g;
}