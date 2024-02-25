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

	int t, n;
	cin >> t;
	char ch;
	while (t--)
	{
		//cin >> n;
		ll ans = 0;
		fori(i, 0, 10)
		{
			fori(j, 0, 10)
			{
				cin >> ch;
				if (ch == 'X')
				{
					if (i == 0 or i == 9 or j == 0 or j == 9)
						ans += 1;
					else if (i == 1 or i == 8 or j == 1 or j == 8)
						ans += 2;
					else if (i == 2 or i == 7 or j == 2 or j == 7)
						ans += 3;
					else if (i == 3 or i == 6 or j == 3 or j == 6)
						ans += 4; 
					else if (i == 4 or i == 5 or j == 4 or j == 5)
						ans += 5;
				}
			}
		}
		cout << ans << '\n';
	}
	
}