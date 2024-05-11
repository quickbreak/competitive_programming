#include<algorithm>
#include<any>
#include<cassert>
#include<cmath>
#include<cstdio>
#include<deque>
#include<functional>
#include<iostream>
#include<map>
#include<queue>
#include<random>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<vector>

#define fori(it, a, b) for(int it = a; it < b; ++it)
#define all(x) (x).begin(),(x).end()
#define cn cout << '\n'
#define minel(v) *min_element(v.begin(), v.end());
#define maxel(v) *max_element(v.begin(), v.end());
#define sortv(v) sort(v.begin(), v.end());
#define forl(a, k, b) for(long long a = k; a < b; ++a)
#define useless ios_base::sync_with_stdio(false); cin.tie(NULL);
//define int long long;

using namespace std;

using ll = long long;
using str = string;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;

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


int32_t main()
{
	useless;
	/*
	Игра в крестики-нолики на бесконечной плоскости похожа на обычные крестики-нолики: 
	два игрока по очереди ставят свои фигуры (крестики у первого игрока и нолики — у второго) 
	в свободные клетки поля. Побеждает тот игрок, который первым выстроил пять своих фигур 
	по горизонтали, вертикали или одной из диагоналей.
	В логе записаны координаты клеток, в том порядке, в котором игроки ставили свои фигуры. 
	Определите, кто победил в игре или отследите ситуацию, что игроки увлеклись 
	и продолжили игру после победы одного из игроков.
	*/

	/*
	решение:
	* условно игроки красят клетки, каждый своим цветом

	пройдём по всем клеткам:
	если игрок уже находил так, что, когда закрасит эту клетку, 
	у него получится полоса длины 5 (по какой-либо из сторон)
	из его покрасок, он победил
	*/
	
	int n; cin >> n;
	int x, y;
	vector<pair<int, int>>a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first >> a[i].second;
	}


	string ans = "Draw";
	set<pair<int, int>>stf;
	set<pair<int, int>>sts;
	int res = 0;
	for (int i = 0; i < n; ++i) {
		x = a[i].first;
		y = a[i].second;
		// ходит первый
		if (i % 2 == 0) {
			// вертикаль
			res = 0;
			for (int j = 1; j <= 4; ++j) {
				if (stf.find(make_pair(x, y - j)) != stf.end()) {
					++res;
				}
				else break;
			}
			for (int j = 1; j <= 4; ++j) {
				if (stf.find(make_pair(x, y + j)) != stf.end()) {
					++res;
				}
				else break;
			}
			if (res >= 4) {
				if (i < n - 1)
					ans = "Inattention";
				else
					ans = "First";
				break;
			}
			// горизонталь
			res = 0;
			for (int j = 1; j <= 4; ++j) {
				if (stf.find(make_pair(x - j, y)) != stf.end()) {
					++res;
				}
				else break;
			}
			for (int j = 1; j <= 4; ++j) {
				if (stf.find(make_pair(x + j, y)) != stf.end()) {
					++res;
				}
				else break;
			}
			if (res >= 4) {
				if (i < n - 1)
					ans = "Inattention";
				else
					ans = "First";
				break;
			}

			// диагональ 1
			res = 0;
			for (int j = 1; j <= 4; ++j) {
				if (stf.find(make_pair(x - j, y - j)) != stf.end()) {
					++res;
				}
				else break;
			}
			for (int j = 1; j <= 4; ++j) {
				if (stf.find(make_pair(x + j, y + j)) != stf.end()) {
					++res;
				}
				else break;
			}
			if (res >= 4) {
				if (i < n - 1)
					ans = "Inattention";
				else
					ans = "First";
				break;
			}

			// диагональ 2
			res = 0;
			for (int j = 1; j <= 4; ++j) {
				if (stf.find(make_pair(x + j, y - j)) != stf.end()) {
					++res;
				}
				else break;
			}
			for (int j = 1; j <= 4; ++j) {
				if (stf.find(make_pair(x - j, y + j)) != stf.end()) {
					++res;
				}
				else break;
			}
			if (res >= 4) {
				if (i < n - 1)
					ans = "Inattention";
				else
					ans = "First";
				break;
			}



			stf.insert(make_pair(x, y));
		}



		// ходит второй
		else {
			// вертикаль
			res = 0;
			for (int j = 1; j <= 4; ++j) {
				if (sts.find(make_pair(x, y - j)) != sts.end()) {
					++res;
				}
				else break;
			}
			for (int j = 1; j <= 4; ++j) {
				if (sts.find(make_pair(x, y + j)) != sts.end()) {
					++res;
				}
				else break;
			}
			if (res >= 4) {
				if (i < n - 1)
					ans = "Inattention";
				else
					ans = "Second";
				break;
			}

			// горизонталь
			res = 0;
			for (int j = 1; j <= 4; ++j) {
				if (sts.find(make_pair(x - j, y)) != sts.end()) {
					++res;
				}
				else break;
			}
			for (int j = 1; j <= 4; ++j) {
				if (sts.find(make_pair(x + j, y)) != sts.end()) {
					++res;
				}
				else break;
			}
			if (res >= 4) {
				if (i < n - 1)
					ans = "Inattention";
				else
					ans = "Second";
				break;
			}

			// диагональ 1
			res = 0;
			for (int j = 1; j <= 4; ++j) {
				if (sts.find(make_pair(x - j, y - j)) != sts.end()) {
					++res;
				}
				else break;
			}
			for (int j = 1; j <= 4; ++j) {
				if (sts.find(make_pair(x + j, y + j)) != sts.end()) {
					++res;
				}
				else break;
			}
			if (res >= 4) {
				if (i < n - 1)
					ans = "Inattention";
				else
					ans = "Second";
				break;
			}

			// диагональ 2
			res = 0;
			for (int j = 1; j <= 4; ++j) {
				if (sts.find(make_pair(x + j, y - j)) != sts.end()) {
					++res;
				}
				else break;
			}
			for (int j = 1; j <= 4; ++j) {
				if (sts.find(make_pair(x - j, y + j)) != sts.end()) {
					++res;
				}
				else break;
			}
			if (res >= 4) {
				if (i < n - 1)
					ans = "Inattention";
				else
					ans = "Second";
				break;
			}



			sts.insert(make_pair(x, y));
		}
	}
	cout << ans;

}

/*
9
1 1
100 100
1 2
120 120
1 3
110 110
1 4
130 130
1 5

--First
*/
