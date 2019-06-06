#include <cstdio>

typedef long long ll;

const ll MOD = 1e9;

ll n, k, dp[222][222];

ll func(ll a, ll b) {

	if (a == 0) return 1;
	if (b == 1) return 1;
	if (b == 2) return a + 1;

	if (dp[a][b]) return dp[a][b];

	for (ll i = 0; i <= a; i++) {
		dp[a - i][b - 1] = func(a - i, b - 1) % MOD;
		dp[a][b] += dp[a - i][b - 1];
		dp[a][b] %= MOD;
	}

	return dp[a][b];
}

int main() {

	scanf("%lld %lld", &n, &k);

	printf("%lld\n", func(n, k));
}