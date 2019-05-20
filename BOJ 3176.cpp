#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 100000;

int n, k, dep[MAX + 1], parent[MAX + 1][20], maxd[MAX + 1][20], mind[MAX + 1][20];
vector<vector<pair<int, int>>> tree;

void make_tree(int curr, int par) {

	for (auto adj : tree[curr]) {
		int next = adj.first;
		int cost = adj.second;

		if (next == par) continue;

		dep[next] = dep[curr] + 1;
		parent[next][0] = curr;
		maxd[next][0] = mind[next][0] = cost;
		
		make_tree(next, curr);
	}
}

void lca(int u, int v) {

	int res_min = 1e9, res_max = -1e9;

	if (dep[u] > dep[v]) swap(u, v);

	for (int i = 19; i >= 0; i--) {
		int diff = dep[v] - dep[u];
		if (diff >= (1 << i)) {
			res_min = min(res_min, mind[v][i]);
			res_max = max(res_max, maxd[v][i]);
			v = parent[v][i];
		}
	}
	if (u == v) {
		printf("%d %d\n", res_min, res_max);
		return;
	}

	for (int i = 19; i >= 0; i--) {
		if (parent[u][i] != parent[v][i]) {
			res_min = min(res_min, min(mind[v][i], mind[u][i]));
			res_max = max(res_max, max(maxd[v][i], maxd[u][i]));
			u = parent[u][i];
			v = parent[v][i];
		}
	}
	res_min = min(res_min, min(mind[u][0], mind[v][0]));
	res_max = max(res_max, max(maxd[u][0], maxd[v][0]));

	printf("%d %d\n", res_min, res_max);
}

int main() {

	scanf("%d", &n);
	tree.resize(n + 1);

	int a, b, c;
	for (int i = 1; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		tree[a].push_back({ b,c });
		tree[b].push_back({ a,c });
	}

	make_tree(1, 0);
	
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j <= n; j++) {
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
			mind[j][i] = min(mind[j][i - 1], mind[parent[j][i - 1]][i - 1]);
			maxd[j][i] = max(maxd[j][i - 1], maxd[parent[j][i - 1]][i - 1]);
		}
	}

	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &a, &b);
		lca(a, b);
	}
}