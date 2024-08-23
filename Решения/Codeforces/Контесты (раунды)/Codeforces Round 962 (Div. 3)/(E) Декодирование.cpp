#include <iostream>
#include <vector>
#include <map>

using namespace std;

using str = std::string;
using ll = long long;

const ll mod = (ll)1e9 + 7;

#define ReadFast ios_base::sync_with_stdio(false); cin.tie(0);

int main() {
	ReadFast;
	int t; cin >> t;
	str s;
	while (t-- > 0) {
		cin >> s;
		int n = (int)s.size();
		// давайте все нули заменим на -1. Тогда отрезок с одинаковым количеством 0 и 1 - отрезок с суммой = 0.
		vector<int>prefs(n + 1); // Посчитаем префикс-сумму. 
		for (int i = 0; i < n; ++i) {
			prefs[i + 1] = prefs[i] + (s[i] == '0' ? -1 : 1);
		}
		map<int, ll>alls, currs; // сумма -> посчитанная "преф преф сумма"
		for (int i = 0; i <= n; ++i) {
			alls[prefs[i]] += ll(n - i + 1);
		}
		ll ans = 0LL;
		for (int i = 0; i <= n; ++i) {
			currs[prefs[i]] += ll(n - i + 1);
			ans += 1LL * (i + 1) * (alls[prefs[i]] - currs[prefs[i]]);
			ans %= mod;
		}
		cout << ans << '\n';
	}
}