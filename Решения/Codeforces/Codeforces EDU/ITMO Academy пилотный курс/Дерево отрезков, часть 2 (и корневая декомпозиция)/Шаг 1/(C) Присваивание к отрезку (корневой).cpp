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
	vector<pair<int, int>>a, val;

	void build(int n)
	{
		a.assign(n, make_pair(0, 0));
		int groupCount = (a.size() + gSize - 1) / gSize;
		val.assign(groupCount, make_pair(0, 0));
	}

	void set(int l, int r, int value, int time) {
		int gl = l / gSize, gr = r / gSize;
		if (gl == gr)
		{
			for (int i = l; i < r; ++i)
			{
				a[i] = make_pair(value, time);
			}
		}
		else
		{
			for (int i = l; i < (gl + 1) * gSize; ++i)
			{
				a[i] = make_pair(value, time);
			}
			for (int g = gl + 1; g < gr; ++g)
			{
				val[g] = make_pair(value, time);
			}
			for (int i = gr * gSize; i < r; ++i)
			{
				a[i] = make_pair(value, time);
			}
		}
	}

	int getValue(int index) const {
		int gNum = index / gSize;
		return (a[index].second > val[gNum].second) ? a[index].first : val[gNum].first;
	}
};

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m; cin >> n >> m;

	SqrtDec sd;
	sd.build(n);
	int typ;
	int time = 0;
	while (m-- > 0) {
		++time;
		cin >> typ;
		if (typ == 1) {
			int l, r, value; cin >> l >> r >> value;
			sd.set(l, r, value, time);
		}
		else {
			int index; cin >> index;
			cout << sd.getValue(index) << '\n';
		}
	}
}