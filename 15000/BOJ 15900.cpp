#include <cstdio>
#include <vector>
using namespace std;

int n;
vector<vector<int>> tree;

int dfs(int curr, int par, int cnt) {

	int sum = 0;

	if (curr != 1 && tree[curr].size() == 1) {
		return cnt;
	}

	for (int i = 0; i < tree[curr].size(); i++) {
		int next = tree[curr][i];
		if (next == par) continue;
		sum += dfs(next, curr, cnt + 1);
	}

	return sum;
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

	int res = dfs(1, 0, 0);

	if (res % 2) {
		puts("Yes");
	}
	else {
		puts("No");
	}

}