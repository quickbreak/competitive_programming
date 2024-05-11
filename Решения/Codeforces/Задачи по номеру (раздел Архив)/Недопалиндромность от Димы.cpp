#include <iostream>
#include <vector>


using namespace std;


int main() {
	int n, k; cin >> n >> k;
	long long x, maxx = -1LL*(1e9), sum = 0;
	for (int i = 0; i < k; ++i) {
		cin >> x;
		maxx = max(maxx, x);
		sum += x;
	}
	long long answer = maxx * k - sum;
	for (int i = k; i < n; ++i) {
		cin >> x;
		if (x > maxx) {
			answer += (k - 1) * (x - maxx);
			maxx = x;
		}
		else {
			answer += maxx - x;
		}
	}
	cout << answer;

}