#include<iostream>
#include<cstdio>
#include<cmath>
#include<set>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<any>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<cassert>

#define fori(it, a, b) for(int it = a; it < b; ++it)
#define all(x) (x).begin(),(x).end()
#define cn cout << '\n'
#define minel(v) *min_element(v.begin(), v.end());
#define maxel(v) *max_element(v.begin(), v.end());
#define sortv(v) sort(v.begin(), v.end());
#define forl(a, k, b) for(long long a = k; a < b; ++a)
#define useless ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

using ll = long long;
using str = string;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;

const ll mod = ll(1e9 + 7);

//base ^ p
ll binpow(ll base, ll p)
{
	if (p == 0)
		return 1;
	if (p == 1)
		return base;
	if (p % 2 == 0)
	{
		ll polovina = binpow(base, p / 2);
		return polovina * polovina % mod;
	}
	else
	{
		ll pminus = binpow(base, (p - 1) / 2);
		ll res = pminus * pminus % mod;
		return res * base % mod;
	}
}


bool check(const vector<int>& left, vector<int>& right, int k)
{
	int n = left.size();
	int ukleft = 0, ukright = 0; // будем поддерживать диапазон точек, в которых можем попасть
	// После каждого хода он расширяется на k в обе стороны и сокращается до пересечения
	// с отрезком, в котором игрок должен оказаться на этом ходу
	fori(i, 0, n)
	{
		ukright = min(ukright + k, right[i]);
		ukleft = max(ukleft - k, left[i]);
		if (ukright < left[i] || ukleft > right[i])
			return false;
	}
	return true;
}


int main() // на i шагу должны оказаться в отрезке l[i]..r[i] (i + 1 отрезок может быть левее i отрезка)
{
	useless;

	//freopen("lepus.in", "rt", stdin);
	//freopen("lepus.out", "wt", stdout);

	int t, n; cin >> t;
	while (t-- > 0)
	{
		cin >> n;
		vector<int>left(n);
		vector<int>right(n);
		fori(i, 0, n)
		{
			cin >> left[i] >> right[i];
		}
		int l = -1, r = 1e9 + 1, m;
		while (r - l > 1)
		{
			m = (r + l) / 2;
			if (check(left, right, m))
				r = m;
			else l = m;
		}
		assert(r < 1e9 + 1);
		cout << r;
		cn;

	}

}