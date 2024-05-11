#include<iostream>
#include<cstdio>
#include<cmath>
#include<set>
#include<vector>
#include<algorithm>
#include<stack>
#include<map>

using namespace std;

using ll = long long;
using str = string;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<set<int>>stolbec(m);
	vector<vector<char>>v(n, vector<char>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> v[i][j];
			if (v[i][j] == '#')
			{
				stolbec[j].insert(i);
			}
		}
	}
	vector<vector<int>>stroka(n);
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (v[i][j] == '#')
			{
				stroka[i].push_back(j);
			}
		}
		flag = false;
		if (stroka[i].size() == 0)
			continue;
		for (int j = 0; j < (stroka[i].size()-1); j++)
		{
			if (stolbec[stroka[i][j]] != stolbec[stroka[i][j + 1]])
				flag = true;
		}
		if (flag)
		{
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
/*
3 3
...
.#.
...
*/
}