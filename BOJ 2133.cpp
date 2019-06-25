#include <cstdio>

typedef long long ll;

ll n, dp[33];

int main() {

	scanf("%lld", &n);

	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 3;

	for (ll i = 4; i <= 30; i += 2) {
		dp[i] = 2;
	}

	for (ll i = 2; i <= 30; i += 2) {
		dp[i + 2] += dp[i] * 3;
		for (ll j = i + 4; j <= 30; j += 2) {
			dp[j] += dp[i] * 2;
		}
	}

	printf("%lld\n", dp[n]);
}