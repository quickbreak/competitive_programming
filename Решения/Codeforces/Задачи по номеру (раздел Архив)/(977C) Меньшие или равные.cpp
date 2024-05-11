#include<iostream>
#include<cstdio>
#include<cmath>
#include<set>
#include<vector>
#include<algorithm>
#include<stack>
#include<map>

#define fori(it,a,b) for(int it=a;it<b;it++)
#define all(x) (x).begin(),(x).end()

using namespace std;

using ll = long long;
using str = string;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	vi a(n);
	fori(i, 0, n)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int l = 0, r = 1e9+1;
	int x;
	while (r - l > 1)
	{
		x = (r + l) / 2;
		int pos = upper_bound(a.begin(), a.end(), x) - a.begin();
		if (pos > k)
			r = x;
		else if (pos == k)
		{
			cout << x;
			return 0;
		}
		else 
			l = x;
	}
	cout << -1;
	//999999999
}