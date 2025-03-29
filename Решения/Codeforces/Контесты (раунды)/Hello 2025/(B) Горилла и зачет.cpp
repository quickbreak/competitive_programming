#include <iostream>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	int t; cin >> t;
	int n, k, x, minik;
	while (t-- > 0) {
		map<int, int> cnt;
		multiset<int> st;
		cin >> n >> k; 
		for (int i = 0; i < n; ++i) {
			cin >> x;
			cnt[x]++;
		}
		for (const auto& [y, c] : cnt) {
			st.insert(c);
		}
		while (k > 0 && st.size() > 1) {
			minik = min(k, *st.begin());
			k -= minik;
			int g = *st.begin();
			st.erase(st.begin());
			st.insert(g - minik);
			g = *st.rbegin();
			st.erase(--(st.end()));
			st.insert(g + minik);
			if (*st.begin() == 0) {
				st.erase(st.begin());
			}
		}
		std::cout << st.size() << '\n';
	}
}