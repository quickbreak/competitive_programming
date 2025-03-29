#include<iostream>
#include<vector>

using namespace std;

int main() {
	string s; cin >> s;
	int n = s.length();
	string s_copy = s;
	// all Left
	for (char& ch : s_copy)
		if (ch == '?')
			ch = 'L';
	int ans = 0;
	int minl = 0, maxr = 0;
	int i = 0;
	for (char& ch : s_copy) {
		if (ch == 'R')
			++i;
		else
			--i;
		maxr = max(maxr, i);
		minl = min(minl, i);
	}
	ans = max(ans, maxr - minl);
	// all Right
	s_copy = s;
	for (char& ch : s_copy)
		if (ch == '?')
			ch = 'R';
	minl = 0, maxr = 0;
	i = 0;
	for (char& ch : s_copy) {
		if (ch == 'R')
			++i;
		else
			--i;
		maxr = max(maxr, i);
		minl = min(minl, i);
	}
	ans = max(ans, maxr - minl);
	cout << ans;
}