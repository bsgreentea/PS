#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, par[100100], x, y, c, h, k, sz[100100], chk[100100];

int find(int cur) {
	if (par[cur] == cur) return cur;
	return par[cur] = find(par[cur]);
}

void merge(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return;
	par[u] = v;
	sz[v] += sz[u];
}

int main() {

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		par[i] = i;
		sz[i] = 1;
	}

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		merge(x, y);
	}

	scanf("%d %d %d", &c, &h, &k);

	priority_queue<int> pq;

	chk[find(c)] = 1;
	for (int i = 1; i <= n; i++) {
		if (find(i) == find(h)) continue;
		if (chk[find(i)]) continue;
		chk[find(i)] = 1;
		pq.push(-sz[find(i)]);
	}

	int res = sz[find(c)];

	while (1) {
		if (pq.size() <= k) {
			while (pq.size()) {
				res += -pq.top();
				pq.pop();
			}
			break;
		}
		else pq.pop();
	}

	printf("%d\n", res);
}