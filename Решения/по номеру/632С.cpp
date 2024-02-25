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

	int n; str s;
	cin >> n;
	multiset<string>st;
	while (n--)
	{
		cin >> s;
		st.insert(s);
	}
	while (st.size() > 0)
	{
		cout << *st.begin();
		st.erase(st.begin());
	}
}