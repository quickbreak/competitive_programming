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
	int s;
	cin >> n >> s;
	vector<vector<int>>v(n + 1, vector<int>(s + 1));
	vector<int>w(n + 1);
	vector<int>c(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
	}
	for (int i = 0; i <= n; i++)
	{
		v[i][0] = 0;
	}
	for (int i = 1; i <= s; i++)
	{
		v[0][i] = 0;
	}
	/*for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= s; j++)
		{
			cout << v[i][j] << ' ';
		}
		cout << '\n';
	}*/
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= s; j++)  
		{
			v[i][j] = v[i - 1][j];
		}
		for (int j = 0; j <= s; j++)
		{
			if (j - w[i] >= 0)
			{
				v[i][j] = max(v[i][j], v[i - 1][j - w[i]] + c[i]);
			}
		}
	}
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= s; j++)
		{
			cout << v[i][j] << ' ';
		}
		cout << '\n';
	}
	long long ans = 0;
	pair<int, int>ind;
	for (int i = s; i > -1; i--)
	{
		if (v[n][i] > ans)
		{
			ans = v[n][i];
			ind.first = n;
			ind.second = i;
		}
	}
	/*for (int i = n; i <= 0; i--)
	{
		for (int j = s; j <= 0; j--)
		{
			if (v[i][j] > ans)
			{
				ans = v[i][j];
				ind.first = i;
				ind.second = j;
			}
		}
	}*/
	set<int>res;
	int i, j;
	while (ind.first > 0)
	{
		bool f = false;
		i = ind.first;
		j = ind.second;
		if (v[i-1][j] > 0)
		{
			if (v[i][j] != v[i - 1][j])
			{
				for (int k = 0; k <= i - 1; k++)
				{
					if (c[k] == v[i][j] - v[i - 1][j])
					{
						res.insert(k);
						c[k] = 0;
						f = true;
						ind.first = i - 1;
						break;
					}
				}
			}
		}
		if (v[i-1][j]==0 || !f) {
			if (v[i][j] != v[i - 1][j - w[i]])
			{
				for (int k = 0; k <= i - 1; k++)
				{
					if (c[k] == v[i][j] - v[i - 1][j - w[i]])
					{
						res.insert(k);
						c[k] = 0;
						break;
					}
				}
			}
			ind.first = i - 1;
			ind.second = j - w[i];
		}
	}
	cout << ans << ' ' << res.size()<<'\n';
	while (res.size() > 0)
	{
		cout << *res.begin() << ' ';
		res.erase(res.begin());
	}
}