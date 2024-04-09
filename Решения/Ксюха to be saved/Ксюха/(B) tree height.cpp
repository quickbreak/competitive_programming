#include<iostream>
#include<vector>
#include<queue>


using namespace std;


int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n; cin >> n;
	vector<int>parent_of(n);
	// матрица смежности
	vector<vector<int>>a(n);
	int s;
	for (int i = 0; i < n; ++i)
	{
		cin >> parent_of[i];
		if (parent_of[i] == -1)
		{
			s = i;
			continue;
		}
		a[parent_of[i]].push_back(i);
	}
	vector<int>used(n);
	vector<int>cnt(n);
	queue<int>q;

	cnt[s] = 1;
	for (int j = 0; j < a[s].size(); ++j) {
		q.push(a[s][j]);
	}
	while (q.size()) {
		int u = q.front(); 
		if (!used[u]) {
			used[u] = 1;
			cnt[u] = cnt[parent_of[u]] + 1;
			q.pop();
		}
		else {
			q.pop();
			continue;

		}
		for (int j = 0; j < a[u].size(); ++j) {
			if (!used[a[u][j]]) {
				q.push(a[u][j]);

			}
		}

	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
		ans = max(ans, cnt[i]);
	cout << ans;

}
