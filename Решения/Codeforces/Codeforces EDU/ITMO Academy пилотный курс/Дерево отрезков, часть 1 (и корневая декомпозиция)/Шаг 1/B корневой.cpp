#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

const int inf = (int)1e9 + 7;

struct SqrtDec {
	vector<int>a, gmin;
	int gsize;
	void build(vector<int>& arr)
	{
		a = arr;
		gsize = (int)ceil(sqrt(a.size()));
		gmin = vector<int>(gsize + 1, +inf);
		for (int i = 0; i < gsize; ++i) // блок i
		{
			for (int j = i * gsize; j < std::min((i + 1) * gsize, (int)a.size()); ++j) { // сумма в блоке i
				gmin[i] = min(gmin[i], a[j]);
			}
		}
	}

	void set(int index, int value) {
		int gnum = index / gsize;
		a[index] = value;
		gmin[gnum] = +inf;
		for (int i = gsize * gnum; i < gsize * (gnum + 1); ++i) {
			gmin[gnum] = min(gmin[gnum], a[i]);
		}
	}

	int getMin(int l, int r) {
		int gl = l / gsize, gr = r / gsize;
		int res = +inf;
		if (gl == gr)
		{
			for (int i = l; i < r; ++i) {
				res = min(res, a[i]);
			}
			return res;
		}

		for (int i = l; i < gsize * (gl + 1); ++i)
		{
			res = min(res, a[i]);
		}
		for (int i = gl + 1; i < gr; ++i)
		{
			res = min(res, gmin[i]);
		}
		for (int i = gsize * gr; i < r; ++i)
		{
			res = min(res, a[i]);
		}
		return res;
	}
};

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m; cin >> n >> m;
	vector<int> a(n);
	for (auto& it : a)
		cin >> it;

	SqrtDec sd;
	sd.build(a);
	int typ;
	while (m-- > 0) {
		cin >> typ;
		if (typ == 1) {
			int i, v; cin >> i >> v;
			sd.set(i, v);
		}
		else {
			int l, r; cin >> l >> r;
			cout << sd.getMin(l, r) << '\n';
		}
	}
}
