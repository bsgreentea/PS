#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, map[1010][1010], dp[1010][1010];

int main() {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 0) continue;
			dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
			res = max(res, dp[i][j]);
		}
	}

	printf("%d\n", res*res);
}