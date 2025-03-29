#include <iostream>
#include <vector>


using namespace std;


void CountDescendant(int vertex, int parent, vector<int>& descendants_count, vector<vector<int>>& adjacency) {
	for (int v : adjacency[vertex]) {
		if (v != parent) {
			CountDescendant(v, vertex, descendants_count, adjacency);
			descendants_count[vertex] += descendants_count[v];
		}
	}
}


int main() {
	int vertex_count; cin >> vertex_count;
	vector<int>descendants_count(vertex_count + 1, 1);
	int u, v;
	vector<vector<int>>adjacency(vertex_count + 1);
	while (vertex_count-- > 1) {
		cin >> u >> v;
		adjacency[u].push_back(v);
		adjacency[v].push_back(u);
	}
	CountDescendant(1, 0, descendants_count, adjacency);
	for (int i = 1; i < descendants_count.size(); ++i) {
		cout << descendants_count[i] << ' ';
	}
}
