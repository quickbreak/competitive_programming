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

	int t, n, k;
	cin >> t;
	str s;
	while (t--)
	{
		cin >> n >> k;
		cin >> s;
		int ukb = -1;
		int i = 0;
		int ans = 0;
		while (i < n)
		{
			if (s[i] == 'B')//встретил чёрную
			{
				ans++;
				i = i + k;
			}
			else i++;
		}
		cout << ans << '\n';
	}
}