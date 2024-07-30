/*
Корневая декомпозиция
*/
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

// (int)sqrt(1e5)
const int gSize = (int)sqrt(1e5);

struct SqrtDec {
	vector<int>a, maximus;

	void build(int n)
	{
		a.assign(n, 0);
		int groupcount = (a.size() + gSize - 1) / gSize;
		maximus.assign(groupcount, 0);
	}

	void reMax(int l, int r, int value) {
		int gl = l / gSize, gr = r / gSize;
		if (gl == gr)
		{
			for (int i = l; i < r; ++i)
			{
				a[i] = std::max(a[i], value);
			}
		}
		else
		{
			for (int i = l; i < (gl + 1) * gSize; ++i)
			{
				a[i] = std::max(a[i], value);
			}
			for (int g = gl + 1; g < gr; ++g)
			{
				maximus[g] = std::max(maximus[g], value);
			}
			for (int i = gr * gSize; i < r; ++i)
			{
				a[i] = std::max(a[i], value);
			}
		}
	}

	int getValue(int index) const {
		int gNum = index / gSize;
		return std::max(a[index], maximus[gNum]);
	}
};

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m; cin >> n >> m;

	SqrtDec sd;
	sd.build(n);
	int typ;
	while (m-- > 0) {
		cin >> typ;
		if (typ == 1) {
			int l, r, value; cin >> l >> r >> value;
			sd.reMax(l, r, value);
		}
		else {
			int index; cin >> index;
			cout << sd.getValue(index) << '\n';
		}
	}
}