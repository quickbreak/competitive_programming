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
	vector<long long> A;
	vector<long long> B;
	cin >> n;
	long long u, h;
	for (int i = 0; i < n; i++)
	{
		cin >> u >> h;
		if (u == 1)
			A.push_back(h);
		else
			B.push_back(h);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> h;
		long long otv = 0;
		if (A.size() > 0)
		{
			long long l = 0;
			long long r = A.size() - 1;
			long long mm;
			while (r - l > 1)
			{
				mm = (r + l) / 2;
				if (A[mm] > h)
					r = mm;
				else
					l = mm;
			}
			mm = r;
			if (A[mm] <= h)
				otv += r + 1;
			else
				if (A[mm - 1] <= h)
					otv += l + 1;
				else
					otv += 0;
		}

		if (B.size() > 0)
		{
			h = -h;
			long long l = 0;
			long long r = B.size() - 1;
			long long mm;
			while (r - l > 1)
			{
				mm = (r + l) / 2;
				if (B[mm] > h)
					r = mm;
				else
					l = mm;
			}
			mm = r;
			if (B[mm] <= h)
				otv += r + 1;
			else
				if (B[mm - 1] <= h)
					otv += l + 1;
				else
					otv += 0;
		}


		cout << otv << '\n';
	}
}
