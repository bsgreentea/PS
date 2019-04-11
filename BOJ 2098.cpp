#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 1e9 + 1;

int n, cost[20][20], dp[20][1 << 16];

int traversal(int here, int chk) {

	if (chk == (1 << n) - 1) {
		if (cost[here][0]) return cost[here][0];
		else return INF;
	}

	int& ret = dp[here][chk];
	if (ret) return ret;

	ret = INF;

	for (int i = 0; i < n; i++) {
		if (chk & (1 << i) || cost[here][i] == 0) continue;
		ret = min(ret, traversal(i, chk | (1 << i)) + cost[here][i]);
	}

	return ret;
}

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &cost[i][j]);
		}
	}

	printf("%d\n", traversal(0, 1));
}