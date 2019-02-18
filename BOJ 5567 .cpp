#include <cstdio>
#include <vector>
using namespace std;

int n, m, visited[555];
vector<vector<int>> vt;

void dfs(int here, int cnt) {

	visited[here] = 1;
	if (cnt == 2) return;

	for (int there : vt[here]) {
		dfs(there, cnt + 1);
	}
}

int main() {

	scanf("%d %d", &n, &m);
	vt.resize(n + 1);

	int a, b;
	while (m--) {
		scanf("%d %d", &a, &b);
		vt[a].push_back(b);
		vt[b].push_back(a);
	}

	dfs(1, 0);

	int res = 0;
	for (int i = 2; i <= n; i++) {
		res += visited[i];
	}

	printf("%d\n", res);
}