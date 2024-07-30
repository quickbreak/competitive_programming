/*
Корневая декомпозиция
*/
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

// (int)sqrt(1e5)
const int gsize = (int)sqrt(1e5);

struct SqrtDec {
	vector<long long>a, balance;

	void build(int n)
	{
		a.assign(n, 0LL);
		int groupcount = (a.size() + gsize - 1) / gsize;
		balance.assign(groupcount, 0LL);
	}

	void add(int l, int r, int value) {
		int gl = l / gsize, gr = r / gsize;
		if (gl == gr)
		{
			for (int i = l; i < r; ++i)
			{
				a[i] += value;
			}
		}
		else
		{
			for (int i = l; i < (gl + 1) * gsize; ++i)
			{
				a[i] += value;
			}
			for (int g = gl + 1; g < gr; ++g)
			{
				balance[g] += value;
			}
			for (int i = gr * gsize; i < r; ++i)
			{
				a[i] += value;
			}
		}
	}

	long long getValue(int index) {
		int gNum = index / gsize;
		long long res = balance[gNum];
		return 1LL*(res + a[index]);
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
			sd.add(l, r, value);
		}
		else {
			int index; cin >> index;
			cout << sd.getValue(index) << '\n';
		}
	}
}