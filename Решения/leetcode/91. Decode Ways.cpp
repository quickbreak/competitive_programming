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


class Solution {
public:
	int numDecodings(string s) {
		/*unordered_set<string> st = {
			"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13",
			"14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26"
		};*/
		int n = s.size();
		pair<int, int>d;
		d.first = 1;
		string tre = "";
		tre += s[0];
		d.second = stoi(tre) >= 1 && stoi(tre) <= 26;
		if (d.second == 0)
			return 0;
		int curr = 0;
		for (int i = 1; i < n; ++i) {
			curr = 0;
			tre = s[i];
			if (stoi(tre) >= 1 && stoi(tre) <= 26) {
				curr = d.second;
			}
			tre = s[i - 1] + tre;
			if (s[i - 1] != '0' && stoi(tre) >= 1 && stoi(tre) <= 26) {
				curr += d.first;
			}
			d.first = d.second;
			d.second = curr;
			if (curr == 0)
				return 0;

		}
		return d.second;

	}
};


int main()
{
	useless;

	//freopen("input.in", "rt", stdin);
	//freopen("output.out", "wt", stdout);

	
	Solution S;
	str k; cin >> k;
	cout << S.numDecodings(k);
	// input:1213145 ans:10
}