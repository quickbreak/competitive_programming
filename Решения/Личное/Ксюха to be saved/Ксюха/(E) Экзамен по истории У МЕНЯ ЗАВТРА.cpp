#include<iostream>
#include<set>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, m, x, ans = 0; cin >> n;
	set<int>st;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		st.insert(x);

	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> x;
		if (st.find(x) != st.end()) {
			ans++;
		}

	}
	cout << ans;

}