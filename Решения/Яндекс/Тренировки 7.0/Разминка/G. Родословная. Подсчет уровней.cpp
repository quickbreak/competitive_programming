#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>


using namespace std;


void CountDescendant(int vertex, int parent, vector<int>& heights, vector<vector<int>>& adjacency) {
	heights[vertex] = heights[parent] + 1;
	for (int v : adjacency[vertex]) {
		CountDescendant(v, vertex, heights, adjacency);
	}
}


int main() {
	int vertex_count; cin >> vertex_count;
	vector<pair<string, string>>data(vertex_count - 1);
	map<string, int>correspondence;
	int number = 1;
	unordered_set<string>names;
	for (int i = 0; i < vertex_count - 1; ++i) {
		cin >> data[i].first >> data[i].second;
		++number;
		correspondence[data[i].first] = number;
		names.insert(data[i].first);
		names.insert(data[i].second);
	}
	for (auto& name : names) {
		if (!correspondence.contains(name)) {
			correspondence[name] = 1;
			break;
		}
	}
	vector<int>heights(vertex_count + 1, 0);
	vector<vector<int>>adjacency(vertex_count + 1);
	for (auto& [son, parent] : data) {
		adjacency[correspondence[parent]].push_back(correspondence[son]);
	}
	heights[0] = -1;
	CountDescendant(1, 0, heights, adjacency);
	for (auto& [name, num] : correspondence) {
		cout << name << ' ' << heights[num] << '\n';
	}
}
