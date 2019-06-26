#include <cstdio>
#include <algorithm>
using namespace std;

int n, t, k[101], s[101], dp[101][10101];

int main() {

	scanf("%d %d", &n, &t);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", k + i, s + i);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= t; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - k[i] >= 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - k[i]] + s[i]);
		}
	}

	printf("%d\n", dp[n][t]);
}