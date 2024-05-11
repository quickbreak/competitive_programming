#include<iostream>
#include<vector>
#include<unordered_map>


using namespace std;


int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, k; cin >> n >> k;
	vector<long long>a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];

	}
	unordered_map<int, int>cnt;
	long long ans_sum = -1e18, curr_sum = 0;
	int l = -1, r = -1, ans_l = -1, ans_r = -1, curr_k = 0;
	while (curr_k < k && r < n - 1) {
		if (!cnt.contains(a[++r])) {
			cnt[a[r]] = 0;
			++curr_k;
		}
		++cnt[a[r]];
		curr_sum += a[r];
	}
	if (curr_k < k) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}

	if (curr_sum > ans_sum) {
		ans_sum = curr_sum;
		ans_l = l;
		ans_r = r;
	}
	long long max_sum = 0;
	int max_l = 0;
	while (r < n - 1) {
		if (!cnt.contains(a[++r])) {
			cnt[a[r]] = 0;
			++curr_k;
		}
		++cnt[a[r]];
		curr_sum += a[r];
		if (curr_sum > ans_sum) {
			ans_sum = curr_sum;
			ans_l = l;
			ans_r = r;
		}
		max_l = l;
		max_sum = curr_sum;
		while (curr_k > k) {
			--cnt[a[++l]];
			if (cnt[a[l]] == 0)
				--curr_k;

			curr_sum -= a[l];
			if (curr_sum >= ans_sum) {
				ans_sum = curr_sum;
				ans_l = l + 1;
				ans_r = r;
			}

			if (curr_sum >= max_sum) {
				max_sum = curr_sum;
				max_l = l + 1;
			}

		}

		curr_sum = max_sum;
		l = max_l;

	}
	ans_l = max(ans_l + 1, 1);
	ans_r = max(ans_r + 1, 1);
	/*if (a[ans_l - 1] == 0)
		ans_l++;
	if (a[ans_r - 1] == 0)
		ans_r--;*/
	cout << ans_sum << '\n' << ans_l << ' ' << ans_r;
    
}

/*
10 3
3 -4 -3 -2 -2 3 0 1 -5 -4
*/