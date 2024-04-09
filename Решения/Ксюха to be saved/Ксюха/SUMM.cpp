#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>


using namespace std;

//bool cmp(const pair<int,int>&l, const pair<int,int>&r) {
//	return less<pair<int, int>>{}(l, r);
//}

int main() {

	//freopen("in.txt", "rt", stdin);
	//freopen("out.txt", "wt", stdout);

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, k; cin >> n >> k;
	vector<int>a(n);
	vector<long long>prefs(n+1); // prefs[i] == сумма первых i элементов
	prefs[0] = 0;
	vector<pair<int, int>>cnt(n); // cnt[i] == количество вхождений a[i] элемента в текущий подотрезок
	vector<long long>min_prefs(n + 1); // минимальная сумма подотрезка 0..uk из подотрезков отрезка 0..i
	min_prefs[0] = 0;
	int uk;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		prefs[i + 1] = (prefs[i] + a[i]);
		cnt[i] = { a[i], 0 };
		/*if (i == 0)
		{
			min_prefs[i + 1] = a[0];
			continue;
		}*/
		min_prefs[i + 1] = min(min_prefs[i], prefs[i + 1]);

	}
	sort(cnt.begin(), cnt.end());
	for (int i = 1; i < n; ++i) {
		if (cnt[i].first == cnt[i - 1].first)
			cnt[i].second = (int)1e9;
	}
	long long ans_sum = -1e18, curr_sum = 0;
	int l = 0, r = 0, ans_l = -1, ans_r = -1, curr_k = 0;
	while (r < n && curr_k < k) {
		uk = lower_bound(cnt.begin(), cnt.end(), pair(a[r], 0)) - cnt.begin();
		//assert(uk > -1 && uk < n);
		++cnt[uk].second;
		
		if (cnt[uk].second == 1)
			++curr_k;
		++r;
	}
	if (curr_k < k) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	--r;
	curr_sum = prefs[r + 1];
	if (curr_sum > ans_sum) {
		ans_sum = curr_sum;
		ans_r = r - 1;
		// ans_l тут не узнаешь, потом за O(n) найдешь проходом по min_prefs
	}
	while (curr_k >= k) {
		++l; // когда это плохо? upd: вроде, никогда
		uk = lower_bound(cnt.begin(), cnt.end(), make_pair(a[l - 1], 0)) - cnt.begin();
		--cnt[uk].second;
		if (cnt[uk].second == 0)
			--curr_k;
		if (curr_k < k) {
			--l;
			++cnt[uk].second;
			++curr_k;
			break;
		}
		curr_sum = prefs[r + 1] - min(min_prefs[l + 1 - 1], 0LL);
		if (curr_sum > ans_sum) {
			ans_sum = curr_sum;
			ans_r = r;
			// ans_l тут не узнаешь, потом за O(n) найдешь проходом по min_prefs
		}
	}
	for (r = r + 1; r < n; ++r) {
		uk = lower_bound(cnt.begin(), cnt.end(), pair(a[r], 0)) - cnt.begin();
		//assert(uk > -1 && uk < n);
		++cnt[uk].second;
		curr_sum = prefs[r + 1] - min(min_prefs[l], 0LL);
		if (curr_sum > ans_sum) {
			ans_sum = curr_sum;
			ans_r = r;
			// ans_l тут не узнаешь, потом за O(n) найдешь проходом по min_prefs
		}
		if (cnt[uk].second == 1)
			++curr_k;
		while (curr_k >= k) {
			++l; // когда это плохо? upd: вроде, никогда
			uk = lower_bound(cnt.begin(), cnt.end(), make_pair(a[l - 1], 0)) - cnt.begin();
			--cnt[uk].second;
			if (cnt[uk].second == 0)
				--curr_k;
			if (curr_k < k) {
				--l;
				++cnt[uk].second;
				++curr_k;
				break;
			}
			curr_sum = prefs[r + 1] - min(min_prefs[l + 1 - 1], 0LL);
			if (curr_sum > ans_sum) {
				ans_sum = curr_sum;
				ans_r = r;
				// ans_l тут не узнаешь, потом за O(n) найдешь проходом по min_prefs
			}
		}

	}

	cout << ans_sum << '\n';
	long long finds = prefs[ans_r + 1] - ans_sum;
	for (int l = 0; l <= n; l++) {
		if (min_prefs[l] == finds) {
			ans_l = l;
			break;
		}
	}
	cout << ans_l + 1 << ' ' << ans_r + 1;

}
// l - первый ВХОДЯЩИЙ, r - последний входящий
// в 0-индексации
/*
10 3
3 -4 -3 -2 -2 3 0 1 -5 -4
4
6 8

19 4
-5 4 -4 0 -2 -1 2 4 -3 4 -1 -3 -3 -2 -1 3 -5 0 -2
6
6 10

91 11
-1 4 -5 -1 4 5 4 4 -1 3 5 -1 -3 3 0 -2 2 -3 1 0 5 3 3 5 -3 4 5 -4 -1 -1 -4 1 -4 -2 -4 -1 -4 3 3 4 -4 4 5 -2 -5 4 -1 -5 -1 -2 -5 -2 -5 -4 5 -4 -5 -3 5 4 -1 -4 -1 1 -5 0 -3 -1 -2 4 5 -1 2 5 -3 -3 -3 -4 0 -5 -3 4 5 -1 -4 0 2 4 1 -1 4

8 3
0 -4 0 -4 5 -2 -4 -2
1
3 5

2 2
6 6
impossible

9 8
-5 -4 -5 3 -5 8 -8 -6 -5
impossible
*/