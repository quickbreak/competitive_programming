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
	long long n;
	cin >> n;
	long long b = 1;
	for (long long i = 0; i <= n; i++)
	{
		if ((1 << i) >= n)
		{
			cout << i;
			return 0;
		}
	}
}
