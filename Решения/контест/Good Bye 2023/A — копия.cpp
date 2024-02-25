#include<iostream>
#include<cstdio>
#include<cmath>
#include<set>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<any>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<cassert>

using namespace std;

void solve()
{
	int n, k; cin >> n >> k;
	vector<int> b(n);
	for (int i = 0; i < n; ++i)
		cin >> b[i];
	int mx = 1;
	for (auto i : b) mx *= i;
	if (2023 % mx) { cout << "NO\n"; return; }

	cout << "YES\n";
	cout << 2023 / mx << " ";
	for (int i = 1; i < k; i++) cout << 1 << " ";
	cout << endl;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) solve();
}