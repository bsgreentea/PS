#include <cstdio>
#include <cstring>
using namespace std;

const int MOD = 1e5;

int w, h, dp[2][2][111][111];

int main() {

	scanf("%d %d", &w, &h);

	dp[1][1][1][2] = 1;
	dp[0][0][2][1] = 1;

	for (int i = 1; i <= w; i++) {
		for (int j = 1; j <= h; j++) {
			dp[0][1][i][j] += dp[0][0][i][j - 1];
			dp[0][1][i][j] %= MOD;
			dp[1][1][i][j] += dp[1][1][i][j - 1] + dp[0][1][i][j - 1];
			dp[1][1][i][j] %= MOD;
			dp[1][0][i][j] += dp[1][1][i - 1][j];
			dp[1][0][i][j] %= MOD;
			dp[0][0][i][j] += dp[0][0][i - 1][j] + dp[1][0][i - 1][j];
			dp[0][0][i][j] %= MOD;
		}
	}

	printf("%d\n", (dp[0][0][w][h] + dp[0][1][w][h] + dp[1][0][w][h] + dp[1][1][w][h]) % MOD);
}