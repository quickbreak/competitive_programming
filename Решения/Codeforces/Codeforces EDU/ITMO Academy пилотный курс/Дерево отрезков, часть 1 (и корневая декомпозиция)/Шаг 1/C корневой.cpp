#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

const int inf = (int)1e9 + 7;

struct SqrtDec {
	vector<int>a;
	vector<pair<int, int>>gmincount;
	int gsize = 0;
	void build(vector<int>& arr)
	{
		a = arr;
		gsize = (int)ceil(sqrt(a.size()));
		gmincount = vector<pair<int, int>>(gsize, make_pair(+inf, 0));
		for (int i = 0; i < gsize; ++i) // блок i
		{
			for (int j = i * gsize; j < std::min((i + 1) * gsize, (int)a.size()); ++j) { // элементы в блоке i
				if (a[j] < gmincount[i].first)
				{
					gmincount[i].first = a[j];
					gmincount[i].second = 1;
				}
				else if (a[j] == gmincount[i].first)
				{
					++gmincount[i].second;
				}
			}
		}
	}

	void set(int index, int value) {
		int gnum = index / gsize;
		a[index] = value;

		gmincount[gnum].first = +inf;
		gmincount[gnum].second = 0;

		for (int i = gsize * gnum; i < gsize * (gnum + 1); ++i) {
			if (a[i] < gmincount[gnum].first)
			{
				gmincount[gnum].first = a[i];
				gmincount[gnum].second = 1;
			}
			else if (a[i] == gmincount[gnum].first)
			{
				++gmincount[gnum].second;
			}
		}
	}

	pair<int, int> getMinCount(int l, int r) {
		int gl = l / gsize, gr = r / gsize;
		int res = +inf;
		int count = 0;
		if (gl == gr)
		{
			for (int i = l; i < r; ++i) {
				if (a[i] < res)
				{
					res = a[i];
					count = 1;
				}
				else if (a[i] == res)
				{
					++count;
				}
			}

			return { res, count };
		}

		for (int i = l; i < gsize * (gl + 1); ++i)
		{
			if (a[i] < res)
			{
				res = a[i];
				count = 1;
			}
			else if (a[i] == res)
			{
				++count;
			}
		}
		for (int i = gl + 1; i < gr; ++i)
		{
			if (gmincount[i].first < res)
			{
				res = gmincount[i].first;
				count = gmincount[i].second;
			}
			else if (gmincount[i].first == res)
			{
				count += gmincount[i].second;
			}
		}
		for (int i = gsize * gr; i < r; ++i)
		{
			if (a[i] < res)
			{
				res = a[i];
				count = 1;
			}
			else if (a[i] == res)
			{
				++count;
			}
		}
		return { res, count };
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
			auto p = sd.getMinCount(l, r);
			cout << p.first << ' ' << p.second << '\n';
		}
	}
}
