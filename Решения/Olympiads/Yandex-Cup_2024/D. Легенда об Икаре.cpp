#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

int main() {
	long long l = 0, r = 0;
	long long h = 1;
	string response;
	while (true) {
		cout << h << '\n' << flush;
		cin >> response;
		if (response == "ok") {
			r = h;
			break;
		}
		else if (response == "wet") {
			l = h;
			h *= 2;
		}
		else {
			assert(false);
		}
	}
	while (r - l > 1) {
		h = (r + l) / 2;
		cout << h << '\n' << flush;
		cin >> response;
		if (response == "ok") {
			r = h;
		}
		else if (response == "wet") {
			l = h;
		}
		else {
			assert(false);
		}
	}
	cout << "! " << r;
}