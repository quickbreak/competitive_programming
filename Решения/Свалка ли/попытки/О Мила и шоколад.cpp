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

long long nod(long long a, long long b) {
	if (b == 0)
		return a;
	else
		return(b, a % b);
}

int main()
{
	long long n, a, b, p, q;
	cin >> n >> a >> b >> p >> q;
	long long g = nod(max(a,b), min(a,b));
	long long k1 = n / a * p + q*(n / b - n / g);
	long long k2 = (n / a - n / g) * p + q * (n / b);
	cout << max(k1, k2);
}
