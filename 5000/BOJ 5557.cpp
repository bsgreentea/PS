#include <cstdio>

typedef long long ll;

ll n, num[111], dp[111][22];

int main() {

	scanf("%lld", &n);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", num + i);
	}

	dp[1][num[1]] = 1;

	for (ll i = 2; i < n; i++) {
		for (ll j = 0; j <= 20; j++) {
			ll k = num[i];
			if (0 <= j + k && j + k <= 20) {
				dp[i][j + k] += dp[i - 1][j];
			}
			if (0 <= j - k && j - k <= 20) {
				dp[i][j - k] += dp[i - 1][j];
			}
		}
	}

	printf("%lld\n", dp[n - 1][num[n]]);
}