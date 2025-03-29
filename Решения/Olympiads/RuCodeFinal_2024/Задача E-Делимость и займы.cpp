#include<iostream>

using namespace std;

using ll = long long;

ll ans = 0LL;

void rec(ll n, ll k, ll prev) {
	if (n == 0LL && k > 0LL) {
		return;
	}
	if (k == 0LL) {
		if (n == 0LL) {
			++ans;
			// ans %= 998244353LL; нет нужды
		}
		return;
	}
	for (ll i = 1LL; i <= k; ++i) {
		if (n % i == 0 && n / i <= prev) {
			rec(n - n / i, k - 1LL, n / i);
		}
	}
}

int main() {
	ll n, k; cin >> n >> k;
	rec(n, k, n);
	cout << ans;
}

