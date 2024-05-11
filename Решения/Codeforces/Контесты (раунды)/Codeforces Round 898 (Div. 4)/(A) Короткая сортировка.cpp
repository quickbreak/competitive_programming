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
	str s;
	while (t--)
	{
		cin >> s;
		if (s[0] == 'a' or s[1] == 'b' or s[2] == 'c')
			cout << "YES\n";
		else cout << "NO\n";
	}
}