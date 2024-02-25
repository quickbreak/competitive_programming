#include<iostream>
#include<cstdio>
#include<cmath>
#include<set>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

using ll = long long;
using str = string;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int>len(n);
	for (int i = 0; i < n; i++)
		cin >> len[n-1-i];
	int e = -1;
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{	
		if (i <= e)
		{
			if (len[i] + i > e)
				e = len[i] + i;
		}
		else {
			ans += i - e;
			e = len[i] + i;
		}
	}
	cout << ans;
}