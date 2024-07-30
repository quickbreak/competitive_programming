#include<algorithm>
#include<any>
#include<cassert>
#include<cmath>
#include<cstdio>
#include<deque>
#include<functional>
#include<iostream>
#include<map>
#include<queue>
#include<random>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<vector>

#define fori(it, a, b) for(int it = a; it < b; ++it)
#define all(x) (x).begin(),(x).end()
#define cn cout << '\n'
#define minel(v) *min_element(v.begin(), v.end());
#define maxel(v) *max_element(v.begin(), v.end());
#define sortv(v) sort(v.begin(), v.end());
#define forl(a, k, b) for(long long a = k; a < b; ++a)
#define useless ios_base::sync_with_stdio(false); cin.tie(NULL);
//define int long long;

using namespace std;

using ll = long long;
using str = string;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;

const ll mod = ll(1e9 + 7);


int32_t main()
{
	useless;
	
	int t; cin >> t;
	int n; str s;
	while (--t >= 0)
	{
		cin >> n;
		cin >> s;
		int mid = n / 2;
		int res = 0;
		if (n % 2 == 1)
		{
			res = 1; // deleting middle
			for (int i = 0; i < mid; ++i)
			{
				if (s[mid - i] == s[mid + i + 1])
					++res;
				else
					break;
			}
			for (int i = 0; i < mid; ++i)
			{
				if (s[mid - i - 1] == s[mid + i])
					++res;
				else
					break;
			}
		}
		else
		{
			res = 0;
			for (int i = 0; mid - i - 1 > 0; ++i)
			{
				if (s[mid - i - 1] == s[mid + i + 1])
					++res;
				else
					break;
			}
			for (int i = 0; mid + i < n - 1; ++i)
			{
				if (s[mid - i - 2] == s[mid + i])
					++res;
				else
					break;
			}

			res += 2;
		}

		cout << res << '\n';
	}

}