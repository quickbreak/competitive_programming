#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>

using namespace std;

#define ReadFast ios_base::sync_with_stdio(false); cin.tie(0);

const pair<int*, int> k_pnul = {NULL, 0};

struct PersDSU {
private:
	vector<int>roots, sizes;
	int components_cnt;
	stack<pair<int*, int>>history;
	pair<int*, int>p;
	
	int get_root(int u) {
		return (u == roots[u] ? u : get_root(roots[u]));
	}
public:
	PersDSU(int n) :
		roots(n + 1),
		sizes(n + 1, 1),
		components_cnt(n)
	{
		for(int i = 0; i < n; ++i){
			roots[i] = i;
		}
		history.push(k_pnul);
	}
	void unite(int u, int v) {
		u = get_root(u);
		v = get_root(v);
		if (u == v)
			return;
		if (sizes[u] > sizes[v]) {
			std::swap(u, v);
		}
		history.push({&roots[u], roots[u]});
		history.push({&sizes[v], sizes[v]});
		history.push({&components_cnt, components_cnt});
		roots[u] = v;
		sizes[v] += sizes[u];
		--components_cnt;
	}
	void persist() {
		history.push({NULL, 0});
	}
	void rollback() {
		while(true) {
			p = history.top();
			history.pop();
			if (p == k_pnul) {
				break;
			} else {
				*p.first = p.second;
			}
		}
	}
	int get_components_cnt() {
		return components_cnt;
	}
};

struct Query {
	int right, left, index;
};

bool comp (const Query& a, const Query& b) {
	return a.right < b.right;
}

void Mo(int m, int& q, int group_number, int group_size, vector<pair<int, int>>& edges, vector<vector<Query>>& queries) {
	int u, v;
	for (int i = 1; i <= m; ++i) {
		cin >> edges[i].first >> edges[i].second;
	}
	cin >> q;
	Query qu;
	for (int i = 0; i < q; ++i) {
		cin >> qu.left >> qu.right;
		qu.index = i;
		queries[qu.left / group_size].push_back(qu);
	}
	for (int i = 0; i <= group_number; ++i) {
		sort(queries[i].begin(), queries[i].end(), comp);
	}
}

void solve(int n, int q, int group_number, int group_size, vector<pair<int, int>>& edges, vector<vector<Query>>& queries) {
	vector<int>answers(q);
	int l = -1, r = -1;
	Query qu;
	for (int i = 0; i <= group_number; ++i) {
		PersDSU dsu(n);
		l = r = (i + 1) * group_size;
		for (int j = 0; j < queries[i].size(); ++j) {
			l = (i + 1) * group_size;
			qu = queries[i][j];
			while (r <= qu.right) {
				dsu.unite(edges[r].first, edges[r].second);
				++r;
			}
			dsu.persist();
			while (l > qu.left) {
				--l;
				if (l <= qu.right)
					dsu.unite(edges[l].first, edges[l].second);
			}
			answers[qu.index] = dsu.get_components_cnt();
			dsu.rollback();
		}
	}
	for (int& x : answers) {
		cout << x << '\n';
	}
}

int main() { 
	ReadFast;
	int n, q, m; cin >> n >> m;
	vector<pair<int, int>>edges(m + 1);
	int group_size = (int)sqrt(m);
	int group_number = (m + group_size - 1) / group_size;
	vector<vector<Query>>queries(group_number + 1);
	Mo(m, q, group_number, group_size, edges, queries);
	solve(n, q, group_number, group_size, edges, queries);
}