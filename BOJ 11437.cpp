#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, dep[50500], parent[50500][20];
vector<vector<int>> tree;

void make_tree(int curr, int par) {

	for (int next : tree[curr]) {
		if (next == par) continue;
		dep[next] = dep[curr] + 1;
		parent[next][0] = curr;
		make_tree(next, curr);
	}
}

int lca(int u, int v) {

	if (dep[u] > dep[v]) swap(u, v);

	for (int i = 19; i >= 0; i--) {
		int diff = dep[v] - dep[u];
		if (diff >= (1 << i)) {
			v = parent[v][i];
		}
	}
	if (u == v) return u;

	for (int i = 19; i >= 0; i--) {
		if (parent[u][i] != parent[v][i]) {
			u = parent[u][i];
			v = parent[v][i];
		}
	}

	return parent[u][0];
}

int main() {

	scanf("%d", &n);
	tree.resize(n + 1);

	int a, b;
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	make_tree(1, 0);

	for (int i = 1; i < 20; i++) {
		for (int j = 1; j <= n; j++) {
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
		}
	}

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", lca(a, b));
	}
}