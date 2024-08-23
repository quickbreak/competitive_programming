#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t; cin >> t;
	int n, x;
	int b, res;
	int stopc;
	while (t-- > 0) {
		cin >> n >> x;
		res = 0;
		for (int a = 1; a <= n; ++a) {
			for (int b = 1; b <= n / a; ++b) {
				stopc = min(x - a - b, (n - a*b) / (a + b));
				for (int c = 1; c <= stopc; ++c) {
					// if (a * b + b * c + a * c <= n && a + b + c <= x)   1327ms->109ms
					++res;
				}
			}
		}
		cout << res << '\n';
	}
}
/*
ab + bc + ac <= n   ->   ab <= n   ->   b <= n / a
                    -> ab + c(a+b) <= n; c <= (n-ab)/(a+b)
a + b + c <= x   ->   c <= x - a - b
*/