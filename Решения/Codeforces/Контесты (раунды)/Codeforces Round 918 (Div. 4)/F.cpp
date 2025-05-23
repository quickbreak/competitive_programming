#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;


int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t, n; cin >> t;
	while (t--) {
		cin >> n;// time, r/l, nomer
		vector<pair<int, pair<int, int>>>a;
		int l, r;
		for (int i = 0; i < n; ++i) {
			cin >> l >> r;
			a.push_back({ l, {-1, i} });
			a.push_back({ r, {1, i} });
		}
		sort(a.begin(), a.end());
		int cnt_l = 0, cnt_open = 0, cnt_curr_l = 0;
		vector<int>curr_l(n);
		vector<long long>ans(n);
		for (int i = 0; i < 2 * n; ++i) {
			if (a[i].second.first == -1) {
				curr_l[a[i].second.second] = cnt_l;
				ans[a[i].second.second] = cnt_open;
				cnt_l++;
				cnt_open++;
			}
			else {
				ans[a[i].second.second] += cnt_l - curr_l[a[i].second.second];
				cnt_open--;

			}
		}
		long long sum_of_all = 0;
		for (int i = 0; i < n; ++i) {
			sum_of_all += ans[i] - 1;
		}
		cout << sum_of_all << '\n';

	}
	
}
