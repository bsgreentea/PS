#include <cstdio>
#include <algorithm>
using namespace std;

int n, k, w[111], v[111], dp[111][100100];

int main() {

	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", w + i, v + i);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j] = dp[i - 1][j];
			if(j - w[i] >= 0)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
		}
	}

	printf("%d\n", dp[n][k]);
}