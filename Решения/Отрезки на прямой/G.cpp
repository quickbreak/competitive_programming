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
	int m;
	cin >> m;
	vector<pair<int, int> > A;
	int h1, h2;
	cin >> h1 >> h2;
	pair<int, int> t;
	while (!(h1 == 0 && h2 == 0))
	{
		t.first = h1;
		t.second = h2;
		A.push_back(t);
		cin >> h1 >> h2;
	}
	sort(A.begin(), A.end());
	int q = -1;
	int u = 0;
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i].first <= 0 && A[i].second > u)
		{
			u = A[i].second;
			q = i;
		}
	}
	int d = q;
	if (d == -1)
	{
		cout << "No solution";
		return 0;
	}
	vector<pair<int, int> > otv;
	int y = q;
	for (int i = q + 1; i < A.size(); i++)
	{
		if (A[i].first > A[d].second)
		{
			if (A[i].first <= A[y].second || m <= A[y].second)
			{
				otv.push_back(A[d]);
				d = y;
			}
			else
			{
				cout << "No solution";
				return 0;
			}
		}
		if (A[i].second > A[y].second)
		{
			y = i;
		}
	}
	otv.push_back(A[d]);
	if (A[y].second > A[d].second)
		otv.push_back(A[y]);

	vector<pair<int, int> > res;
	bool f = true;
	for (int i = 0; i < otv.size() && f; i++)
	{
		res.push_back(otv[i]);
		if (otv[i].second >= m)
		{
			f = false;
		}
	}
	if (f)
	{
		cout << "No solution";
		return 0;
	}
	cout << res.size()<<'\n';
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i].first << " " << res[i].second<<'\n';
	}
}