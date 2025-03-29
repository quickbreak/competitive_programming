#include <iostream>
#include <string>


using namespace std;


int main() {
	int n; cin >> n;
	int zero_end_count = 1, one_end_count = 0, two_ones_end_count = 0;
	int zero_end_count_copy = 0;
	for (int i = 1; i <= n; ++i) {
		zero_end_count_copy = zero_end_count; // 1 1 2
		zero_end_count = zero_end_count + one_end_count + two_ones_end_count; // 1 2 4
		two_ones_end_count = one_end_count; // 0 1 1
		one_end_count = zero_end_count_copy; // 1 1 2
	}
	cout << zero_end_count + one_end_count + two_ones_end_count;
}
