#include <cstdio>

typedef long long ll;

const ll MOD = 10007;

ll n, way[1010][2];

int main() {

	scanf("%lld", &n);

	// 0 ¼¼¿î 2*1 / 1 2*2
	way[1][0] = 1;
	way[2][0] = 1;
	way[2][1] = 1 * 2;

	for (int i = 3; i <= n; i++) {
		way[i][0] = (way[i - 1][0] + way[i - 1][1]) % MOD;
		way[i][1] = (way[i - 2][0] + way[i - 2][1]) * 2 % MOD;
	}

	printf("%lld\n", (way[n][0] + way[n][1]) % MOD);
}