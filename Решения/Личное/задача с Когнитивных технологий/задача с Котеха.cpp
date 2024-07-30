#include<iostream>
#include<vector>
#include<cmath>
#include<set>

using namespace std;

// (int)sqrt(1e5)
const int kGroupSize = (int)sqrt(1e5);
const int inf = (int)1e9 + 7;

struct SqrtDec {
	vector<int>a;
	vector<set<int>>sets;

	void build_object(const vector<int>& arr) {
		a = arr;
		int group_count = (a.size() + kGroupSize - 1) / kGroupSize;
		sets.assign(group_count, set<int>{});
		for (int g = 0; g < group_count; ++g) {
			for (int i = g * kGroupSize; i < std::min((g + 1) * kGroupSize, (int)a.size()); ++i) {
				sets[g].insert(a[i]);
			}
		}
	}

	void reflect_value(int index) {
		int group_num = index / kGroupSize;
		a[index] = -a[index];
		sets[group_num].clear();
		for (int i = group_num * kGroupSize; i < std::min((group_num + 1) * kGroupSize, (int)a.size()); ++i) {
			sets[group_num].insert(a[i]);
		}
	}

	int upper_bound(int index) { 
		int r = a.size();
		int left_group = (index + 1) / kGroupSize, right_group = r / kGroupSize;
		int res = +inf;
		if (left_group == right_group) {
			for (int i = index + 1; i < r; ++i) {
				if (a[i] > a[index])
					res = std::min(res, a[i]);
			}
		}
		else {
			for (int i = (index + 1); i < kGroupSize * (left_group + 1); ++i) {
				if (a[i] > a[index])
					res = std::min(res, a[i]);
			}
			for (int g = left_group + 1; g < right_group; ++g) {
				auto it = sets[g].upper_bound(a[index]);
				if (it != sets[g].end()) {
					(res = min(res, *it));
				}
			}
			for (int i = kGroupSize * right_group; i < r; ++i) {
				if (a[i] > a[index])
					res = std::min(res, a[i]);
			}
		}
		return res;
	}
};

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<int> a(n);
	for (auto& it : a) {
		cin >> it;
	}

	SqrtDec SqrtDec_instance;
	SqrtDec_instance.build_object(a);
	int q; cin >> q;
	int query_type;
	while (q-- > 0) {
		cin >> query_type;
		if (query_type == 1) {
			int index; cin >> index;
			--index;
			cout << SqrtDec_instance.upper_bound(index) << '\n';
		}
		else {
			int index; cin >> index;
			--index;
			SqrtDec_instance.reflect_value(index);
		}
	}
}
