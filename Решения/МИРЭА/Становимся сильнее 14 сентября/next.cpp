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

	str s = "asvkdxbjc";
	vi a(10);
	a[0] = -2; a[9] = -3;
	for (char ch : s)
		cout << ch;
	cout << endl;
	for (int x : a)
		cout << x;
	cout << endl;

	int p = (5 > 2 ? 1 : 0);
	cout << p << endl;


}