#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<iomanip>

#define minel(v) *min_element(v.begin(), v.end());
#define maxel(v) *max_element(v.begin(), v.end());
#define sortv(v) sort(v.begin(), v.end());
#define fori(a, k, b) for(int a = k; a < b; ++a)
#define forl(a, k, b) for(long long a = k; a < b; ++a)
#define vec(v) vector<int>v;
#define vec(v,n) vector<int>v(n);
#define longvec(v) vector<long long>v;
#define longvec(v,n) vector<long long>v(n);
#define useless ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

long long nod(long long a, long long b)
{
	if (b == 0)
		return a;
	else return nod(b, a % b);

}

int main() {
	useless;
	int n;
	int t;
	cin >> t;
	int cnt_even = 0, cnt_odd = 0, cnt = 0;
	bool f = false; // нашлось х?
	while (t--)
	{
		cin >> n;
		vector<long long>a(n);
		fori(i, 0, n)
			cin >> a[i];
		f = false;
		fori(x, 1, 100) {
			cnt = 0;
			fori(i, 0, n) {
				fori(j, i + 1, n) {

					if (nod(max(a[i] + x, a[j] + x), min(a[i] + x, a[j] + x)) == 1) {
						++cnt;
					}
				}
			}
			if (cnt == (n * (n - 1) / 2)) {
				f = true;
				break;
			}
		}
		if (f)
			cout << "YES\n";
		else cout << "NO\n";

		//	set<long long>st;
		//	bool f = false; // нашлись одинаковые?
		//	cnt_even = 0;
		//	cnt_odd = 0;
		//	fori(i, 0, n)
		//	{
		//		cin >> a[i];
		//		if (a[i] % 2 == 0)
		//			++cnt_even;
		//		else ++cnt_odd;
		//		if (st.find(a[i]) == st.end())
		//			st.insert(a[i]);
		//		else f = true;
		//	}
		//	if (f || cnt_even > 1 && cnt_odd > 0)
		//		cout << "NO\n";
		//	else cout << "YES\n";
	}
}