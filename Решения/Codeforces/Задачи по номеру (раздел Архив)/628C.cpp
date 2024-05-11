#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int main() {
	int n, k; cin >> n >> k;
	string s; cin >> s;
	int i = -1, r, l;
	string ans = "";
	while (k > 0 && ++i < n) {
		r = 'z' - s[i];
		l = s[i] - 'a';
		if (r > l) {
			r = min(r, k);
			ans += char(s[i] + r);
			k -= r;
		}
		else {
			l = min(l, k);
			ans += char(s[i] - l);
			k -= l;
		}
	}
	assert(k >= 0);
	if (k == 0) {
		while (++i < n) {
			ans += s[i];
		}
	}
	cout << (k > 0 ? "-1" : ans);

}