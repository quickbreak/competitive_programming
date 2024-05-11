#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int get_height(int i, const vector<int>& parent, vector<int>& height) {
	if (i == -1)
		return 0;
	if (height[i] > 0)
		return height[i];
	return height[i] = get_height(parent[i], parent, height) + 1;
}

int main() {
	int n; cin >> n;
	int max_height = 1;
	vector<int>parent(n + 1), height(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> parent[i];
	for (int i = 1; i <= n; ++i)
		max_height = max(max_height, get_height(i, parent, height));
	cout << *max_element(height.begin(), height.end());
}