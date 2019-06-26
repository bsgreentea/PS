#include <cstdio>

const int MAX = 1e6 + 1;
const int MOD = 15746;

int n, tile[MAX][2];

int main() {

	tile[1][0] = 0;
	tile[1][1] = 1;

	tile[2][0] = 1;
	tile[2][1] = 1;

	scanf("%d", &n);

	for (int i = 3; i <= n; i++) {
		tile[i][0] = (tile[i - 2][1] + tile[i - 2][0]) % MOD;
		tile[i][1] = (tile[i - 1][1] + tile[i - 1][0]) % MOD;
	}

	printf("%d\n", (tile[n][1] + tile[n][0]) % MOD);
}