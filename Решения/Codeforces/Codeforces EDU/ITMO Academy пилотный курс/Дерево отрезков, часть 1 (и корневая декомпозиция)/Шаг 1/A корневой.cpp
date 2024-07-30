/*
Корневая декомпозиция
*/
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

const int kGroupSize = (int)sqrt(1e5);

struct SqrtDec {
	vector<long long>a, summa;

	void build_object(vector<long long>& arr) {  // FunctionName, but accessor
		a = arr;
		int group_count = (a.size() + kGroupSize - 1) / kGroupSize;
		summa.assign(group_count, 0LL);
		for (int i = 0; i < group_count; ++i) {
			for (int j = i * kGroupSize; j < std::min((i + 1) * kGroupSize, (int)a.size()); ++j) {
				summa[i] += a[j];
			}
		}
	}

	void change_value(int index, int value) {  // FunctionName, but mutator
		int group_num = index / kGroupSize;
		summa[group_num] -= a[index];
		summa[group_num] += value;
		a[index] = value;
	}

	long long get_sum(int l, int r) {  // FunctionName, but mutator
		int left_group = l / kGroupSize, right_group = r / kGroupSize;
		long long res = 0;
		if (left_group == right_group) {
			for (int i = l; i < r; ++i) {
				res += a[i];
			}
		} else {
			for (int i = l; i < kGroupSize * (left_group + 1); ++i) {
				res += a[i];
			}
			for (int i = left_group + 1; i < right_group; ++i) {
				res += summa[i];
			}
			for (int i = kGroupSize * right_group; i < r; ++i) {
				res += a[i];
			}
		}
		return res;
	}
};

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m; cin >> n >> m;
	vector<long long> a(n);
	for (auto& it : a)
		cin >> it;

	SqrtDec SqrtDec_instance;
	SqrtDec_instance.build_object(a);
	int query_type;
	while (m-- > 0) {
		cin >> query_type;
		if (query_type == 1) {
			int i, v; cin >> i >> v;
			SqrtDec_instance.change_value(i, v);
		} else {
			int l, r; cin >> l >> r;
			cout << SqrtDec_instance.get_sum(l, r) << '\n';
		}
	}
}
