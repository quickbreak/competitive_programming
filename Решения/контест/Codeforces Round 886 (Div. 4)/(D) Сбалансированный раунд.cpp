#include<iostream>
#include<cstdio>
#include<cmath>
#include<set>
#include<vector>
#include<algorithm>
#include<stack>
#include<map>

#define fori(it,a,b) for(int it=a;it<b;it++)

using namespace std;

using ll = long long;
using str = string;
using ld = long double;
using vi = vector<int>;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	/*str s = "asvkdxbjc";
	vi a(10);
	a[0] = -2; a[9] = -3;
	for (char ch : s)
		cout << ch;
	cout << endl;
	for (int x : a)
		cout << x;
	cout << endl;

	int p = (5 > 2 ? 1 : 0);
	cout << p << endl;*/

	//для каждой задачи посчитать расстояние до ближайшей задачи, отличающейся не более чем на k (если таких нет, её dist[i]=inf)
	//найти подмассив минимальной суммы?
	int t, n, k, ans, uk;
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		vi a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a.begin(), a.end());
		ans = 1000000; uk = -1;
		fori(i, 0, n-1)
		{
			if (a[i + 1] - a[i] > k)
			{
				ans = min(ans, n - (i - uk));
				uk = i;
			}
		}
		ans = min(ans, n - (n-1 - uk));
		cout << ans << endl;
	}
}