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
	int n, m;
	cin >> n >> m;
	int* A;
	A = new int[n];
	long long buf;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	long long l, r, mid;
	for (int i = 0; i < m; i++)
	{
		l = 0;
		r = n - 1;
		cin >> buf;	
		while (r - l > 1)
		{
			mid = (r + l) / 2;
			if (A[mid] > buf)
				r = mid;
			else l = mid;
		}
		if (A[l] == buf)
			cout << l + 1 << '\n';
		else if (A[r] == buf)
			cout << r + 1 << '\n';
		else cout << "-1\n";
	}
}
