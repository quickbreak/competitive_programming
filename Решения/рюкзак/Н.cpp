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
	int n, m;
	cin >> n >> m;
	vector<vector<long long>>A(m + 1, vector<long long>(n + 1, -1));
	A[0][0] = 0;
	vector<long long>B(n + 1);
	long long c0, d0;
	cin >> c0 >> d0;
	for (int i = 1; i <= n; i++)
	{
		if (i % c0 == 0)
			A[0][i] = A[0][i - c0] + d0;
	}
	vector<pair<pair<long long, long long>, pair<long long, long long>>>G(m + 1);
	for (int i = 1; i <= m; i++)
		cin >> G[i].first.first >> G[i].first.second >> G[i].second.first >> G[i].second.second;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			A[i][j] = A[i - 1][j];
			B[j] = 0;
		}
		for (int j = 0; j <= n; j++)
		{
			if (A[i][j] != -1)
			{
				for (int h = 1; h <= G[i].first.first / G[i].first.second && h * G[i].second.first + j <= n; h++)
					B[h * G[i].second.first + j] = max(B[h * G[i].second.first + j], A[i][j] + h * G[i].second.second);
			}
			A[i][j] = max(A[i][j], B[j]);
		}
	}
	long long otv = 0;
	for (int i = 0; i <= n; i++)
		otv = max(otv, A[m][i]);
	cout << otv;
}