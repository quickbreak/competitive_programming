#include<iostream>
#include <numeric>

using namespace std;

using ll = long long;

int main() {
	ll a, b, c;
	cin >> a >> b >> c;
	long long n; cin >> n;
	ll l = 1, r = 1'000'000'000'000'000'001, m;
	ll common;
	while (r - l > 1) {
		m = (r + l) / 2;
		common = lcm(lcm(a, b), c);
		if (m / lcm(a, b) - m / common + m / lcm(a, c) - m / common + m / lcm(c, b) - m / common >= n) {
			r = m;
		}
		else
			l = m;
	}
	if (r < 1'000'000'000'000'000'001)
		cout << r;
	else
		cout << -1;
}